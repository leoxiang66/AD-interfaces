#ifndef PERCEPTION_DETECTEDBOX_HPP
#define PERCEPTION_DETECTEDBOX_HPP

#include "BoxCoordinate.hpp"
#include <string>

class DetectedBox {
public:
    BoxCoordinate coord;
    float conf;
    std::string label;

    DetectedBox(const BoxCoordinate& coord, float conf, const std::string& label)
        : coord(coord), conf(conf), label(label) {}

    friend std::ostream& operator<<(std::ostream& os, const DetectedBox& detectedBox) {
        os << "DetectedBox(coord=" << detectedBox.coord << ", conf=" << detectedBox.conf
           << ", label='" << detectedBox.label << "')";
        return os;
    }
};

#endif // PERCEPTION_DETECTEDBOX_HPP