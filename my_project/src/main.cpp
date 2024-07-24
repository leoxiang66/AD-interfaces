#include <iostream>
#include <opencv2/opencv.hpp>
#include "DummyPerceptor.hpp"

int main() {
    // Create a DummyPerceptor object
    DummyPerceptor perceptor;

    // Load test images
    std::vector<cv::Mat> images;
    images.emplace_back(cv::imread("imgs/image1.jpg"));
    images.emplace_back(cv::imread("imgs/image2.jpg"));

    // Check if the images were loaded successfully
    for (const auto& image : images) {
        if (image.empty()) {
            std::cout << "Failed to load an image!" << std::endl;
            return -1;
        }
    }

    // Perform object detection
    std::vector<std::vector<DetectedBox>> detections = perceptor.object_detection(images);

    // Print the detection results
    for (size_t i = 0; i < detections.size(); ++i) {
        std::cout << "Detections for image " << i << ":" << std::endl;
        for (const auto& detection : detections[i]) {
            std::cout << detection << std::endl;
        }
    }

    // Display the images with the detection results
    for (size_t i = 0; i < images.size(); ++i) {
        cv::Mat image_with_detections = images[i].clone();
        for (const auto& detection : detections[i]) {
            cv::rectangle(image_with_detections, 
                          cv::Point(detection.coord.x_min, detection.coord.y_min),
                          cv::Point(detection.coord.x_max, detection.coord.y_max),
                          cv::Scalar(0, 255, 0), 2);
        }
        cv::imshow("Image " + std::to_string(i), image_with_detections);
    }
    cv::waitKey(0);

    return 0;
}