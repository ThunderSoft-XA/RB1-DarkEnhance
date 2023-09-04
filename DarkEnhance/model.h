#include <torch/torch.h>
#include <torch/script.h>
#include <fstream>

// Neural Network models for image enhancement
struct EnhanceNet : public torch::nn::Module {
public:
    EnhanceNet() {  
        this->relu = torch::nn::ReLU(torch::nn::ReLUOptions().inplace(true)); // Define the ReLU activation function
        int number_f = 32; // Define the number of channels of the feature map
        torch::manual_seed(3);
        this->e_conv1 = torch::nn::Conv2d(torch::nn::Conv2dOptions(3, number_f, 3).stride(1).padding(1).bias(true)); // First convolutional layer
        torch::manual_seed(3);
        this->e_conv2 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f, number_f, 3).stride(1).padding(1).bias(true)); // Second convolutional layer
        torch::manual_seed(3);
        this->e_conv3 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f, number_f, 3).stride(1).padding(1).bias(true)); // Third convolutional layer
        torch::manual_seed(3);
        this->e_conv4 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f, number_f, 3).stride(1).padding(1).bias(true)); // Fourth convolutional layer
        torch::manual_seed(3);
        this->e_conv5 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f * 2, number_f, 3).stride(1).padding(1).bias(true)); // Fifth convolutional layer
        torch::manual_seed(3);
        this->e_conv6 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f * 2, number_f, 3).stride(1).padding(1).bias(true)); // Sixth convolutional layer
        torch::manual_seed(3);
        this->e_conv7 = torch::nn::Conv2d(torch::nn::Conv2dOptions(number_f * 2, 24, 3).stride(1).padding(1).bias(true)); // Seventh convolutional layer
        //Loading the weights file
        torch::jit::script::Module pretrained_module = torch::jit::load("../cfg/model.pt");
        //Assign weights to each convolutional layer
        for (const auto& named_param : pretrained_module.named_parameters()) {
            if (named_param.name == "e_conv1.weight") 
            {
                this->e_conv1->weight = named_param.value;
            }
            else if(named_param.name == "e_conv2.weight")
            {
                this->e_conv2->weight = named_param.value;
            }
            else if(named_param.name == "e_conv3.weight")
            {
                this->e_conv3->weight = named_param.value;
            }
            else if(named_param.name == "e_conv4.weight")
            {
                this->e_conv4->weight = named_param.value;
            }
            else if(named_param.name == "e_conv5.weight")
            {
                this->e_conv5->weight = named_param.value;
            }
            else if(named_param.name == "e_conv6.weight")
            {
                this->e_conv6->weight = named_param.value;
            }
            else if(named_param.name == "e_conv7.weight")
            {
                this->e_conv7->weight = named_param.value;
            }
        } 
    }

    torch::Tensor forward(torch::Tensor x) {
        torch::Tensor x1 = this->relu(this->e_conv1->forward(x)); // The output of the first convolutional layer goes through the ReLU activation function
        torch::Tensor x2 = this->relu(this->e_conv2->forward(x1)); // The output of the second convolutional layer goes through the ReLU activation function
        torch::Tensor x3 = this->relu(this->e_conv3->forward(x2)); // The output of the third convolutional layer goes through the ReLU activation function
        torch::Tensor x4 = this->relu(this->e_conv4->forward(x3)); // The output of the fourth convolutional layer goes through the ReLU activation function
        // After concatenating the outputs of the third and fourth convolutional layers in the channel dimension, it goes through the fifth convolutional layer and ReLU activation function
        torch::Tensor x5 = this->relu(this->e_conv5->forward(torch::cat({x3, x4}, 1)));
        // After concatenating the outputs of the second and fifth convolutional layers in the channel dimension, they go through the sixth convolutional layer and ReLU activation function
        torch::Tensor x6 = this->relu(this->e_conv6->forward(torch::cat({x2, x5}, 1)));
        // After concatenating the output of the first convolutional layer and the sixth convolutional layer in the channel dimension, it goes through the seventh convolutional layer and Relu activation function
        torch::Tensor x_r = torch::tanh(e_conv7->forward(torch::cat({x1, x6}, 1)));
        
        std::vector<torch::Tensor> r_list = torch::split(x_r, 3, 1); // Split the output into a list by the number of channels

        for (const auto& r : r_list) {
            x = x + r * (torch::pow(x, 2) - x-0.1); // The input is augmented using a residual block
        }
        
        return x; // Returns the tensor that stores the enhanced image information
    }

private:
    torch::nn::ReLU relu;
    torch::nn::Conv2d e_conv1 = nullptr;
    torch::nn::Conv2d e_conv2 = nullptr;
    torch::nn::Conv2d e_conv3 = nullptr;
    torch::nn::Conv2d e_conv4 = nullptr;
    torch::nn::Conv2d e_conv5 = nullptr;
    torch::nn::Conv2d e_conv6 = nullptr;
    torch::nn::Conv2d e_conv7 = nullptr;
};

