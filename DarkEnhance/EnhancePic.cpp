#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <opencv2/opencv.hpp>
#include "model.h"

//Deleting directories
int remove_all(const std::string& file_path) {
    DIR* dir = opendir(file_path.c_str());
    if (dir == nullptr) {
        return -1; 
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string entry_name = entry->d_name;

        if (entry_name != "." && entry_name != "..") {
            std::string full_entry_path = file_path + "/" + entry_name;
            struct stat entry_stat;
            if (lstat(full_entry_path.c_str(), &entry_stat) != 0) {
                closedir(dir);
                return -1; 
            }

            if (S_ISDIR(entry_stat.st_mode)) {
                if (remove_all(full_entry_path) != 0) {
                    closedir(dir);
                    return -1; 
                }
            } else {
                if (unlink(full_entry_path.c_str()) != 0) {
                    closedir(dir);
                    return -1; 
                }
            }
        }
    }

    closedir(dir);

    if (rmdir(file_path.c_str()) != 0) {
        return -1; 
    }

    return 0;
}

//Creating a directory
int create_directory(const std::string& file_path) {
    if (mkdir(file_path.c_str(), 0777) != 0) {
        std::cout << "Failed to create directory: " << strerror(errno) << std::endl;
        return -errno;
    }

    return 0;
}

// Used to calculate the brightness of an image
float brightness(cv::Mat& image) {
    cv::Mat3b image_rgb;
    cv::cvtColor(image, image_rgb, cv::COLOR_BGR2RGB);  // The order of the color channels of the transformed image is RGB

    // Calculate the brightness of the image
    cv::Scalar mean = cv::mean(image_rgb);
    double r = mean[0];
    double g = mean[1];
    double b = mean[2];

    return std::sqrt(0.241 * (r * r) + 0.691 * (g * g) + 0.068 * (b * b));
}

void lowlight(cv::Mat image, std::string name) {
    // The images were converted to torch tensors and normalized
    torch::Tensor data_lowlight = torch::from_blob(image.data, {image.rows, image.cols, image.channels()}, torch::kByte) / 255.0;
    data_lowlight = data_lowlight.to(torch::kFloat);
    data_lowlight = data_lowlight.permute({2, 0, 1});
    
    data_lowlight = data_lowlight.unsqueeze(0);
    EnhanceNet DCE_net = EnhanceNet();

    torch::Tensor enhanced_image = DCE_net.forward(data_lowlight); // Low-light images are enhanced
    enhanced_image = enhanced_image.squeeze(); // Remove the dimension where the dimension of the output tensor is one
    // Convert tensors to OpenCV images
    cv::Mat enhanced_image_cv(enhanced_image.size(1), enhanced_image.size(2), CV_32FC3, enhanced_image.data_ptr<float>());    
    cv::cvtColor(enhanced_image_cv, enhanced_image_cv, cv::COLOR_RGB2BGR);
    // The images were normalized to the range 0-255
    cv::normalize(enhanced_image_cv, enhanced_image_cv, 0, 255, cv::NORM_MINMAX, CV_8UC3);
    //Obtain the brightness of the enhanced image
    float value = brightness(enhanced_image_cv);
    std::cout<<name<<" after light value is : "<<value<<std::endl;

    if(cv::imwrite("../r_images/" + name, enhanced_image_cv))
    {
        std::cout<<"Enhance Success !"<<std::endl;
    }
    else
    {
        std::cout<<"Enhance False !"<<std::endl;
    }
}

int main() {
    torch::NoGradGuard no_grad;
    std::string filePath = "../images"; //The directory to store the images before processing
    std::string file_path = "../r_images"; //Directory to store the processed images
    std::vector<std::string> test_list;
    cv::glob(filePath + "/*", test_list); //Read information about all pending images in the folder
    //Create a directory to store the processed images
    try {
        remove_all(file_path);
        create_directory(file_path);
    } catch (const std::exception& e) {
        create_directory(file_path);
    }
    //Process each pending image
    for (const std::string& image_path : test_list) {
        std::string name = image_path.substr(image_path.find_last_of('/') + 1);
        cv::Mat image = cv::imread(image_path);
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        float value_1 = brightness(image);
        std::cout<<name<<" before light value is : "<<value_1<<std::endl;
        //The brightness of photos below 200 is enhanced, and those above 200 are directly stored in the result directory
        if (brightness(image) < 200) {
            lowlight(image, name);
        } else {
            cv::imwrite(file_path + "/" + name, image);
            std::cout<<"The image does not need to be brightened!"<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    return 0;
}


