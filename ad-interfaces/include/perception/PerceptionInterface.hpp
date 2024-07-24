#ifndef PERCEPTION_PERCEPTIONINTERFACE_HPP
#define PERCEPTION_PERCEPTIONINTERFACE_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include "DetectedBox.hpp"

class PerceptionInterface {
public:
    virtual ~PerceptionInterface() = default;
    virtual std::vector<std::vector<DetectedBox>> object_detection(const std::vector<cv::Mat>& images) = 0;
};

#endif // PERCEPTION_PERCEPTIONINTERFACE_HPP