#ifndef DUMMYPERCEPTOR_HPP
#define DUMMYPERCEPTOR_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include <perception/CameraDetectorInterface.hpp>
#include <perception/DetectedBox.hpp>
#include <perception/BoxCoordinate.hpp>

class DummyPerceptor : public CameraDetectorInterface {
public:
    std::vector<std::vector<DetectedBox>> object_detection(const std::vector<cv::Mat>& images) override {
        std::vector<std::vector<DetectedBox>> detections;

        for (const auto& image : images) {
            std::vector<DetectedBox> image_detections;

            // Generate a dummy detection box at the center of each image
            float x_min = image.cols * 0.25f;
            float y_min = image.rows * 0.25f;
            float x_max = image.cols * 0.75f;
            float y_max = image.rows * 0.75f;
            BoxCoordinate coord(x_min, y_min, x_max, y_max);

            // Create a dummy detection
            DetectedBox detection(coord, 0.8f, "dummy_object");
            image_detections.push_back(detection);

            detections.push_back(image_detections);
        }

        return detections;
    }
};

#endif // DUMMYPERCEPTOR_HPP