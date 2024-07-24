#ifndef PERCEPTION_CAMERADETECTORINTERFACE_HPP
#define PERCEPTION_CAMERADETECTORINTERFACE_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include "DetectedBox.hpp"

class CameraDetectorInterface {
public:
    virtual ~CameraDetectorInterface() = default;
    virtual std::vector<std::vector<DetectedBox>> image_detection(const std::vector<cv::Mat>& images) = 0;
};

#endif // PERCEPTION_CAMERADETECTORINTERFACE_HPP