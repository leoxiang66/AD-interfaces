#ifndef PERCEPTION_BOXCOORDINATE_HPP
#define PERCEPTION_BOXCOORDINATE_HPP

#include <iostream>

class BoxCoordinate {
public:
    float x_min, y_min, x_max, y_max;

    BoxCoordinate(float x_min, float y_min, float x_max, float y_max)
        : x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max) {}

    friend std::ostream& operator<<(std::ostream& os, const BoxCoordinate& coord) {
        os << "BoxCoordinate(x_min=" << coord.x_min << ", y_min=" << coord.y_min
           << ", x_max=" << coord.x_max << ", y_max=" << coord.y_max << ")";
        return os;
    }
};

#endif // PERCEPTION_BOXCOORDINATE_HPP