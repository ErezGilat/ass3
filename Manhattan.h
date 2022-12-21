#ifndef MANHATTAN_H_
#define MANHATTAN_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Distance.h"
// Manhattan distance class - inherits from Distance
class Manhattan : public Distance {
public:
    Manhattan();
    virtual ~Manhattan();
    double calculateDistance(std::vector<double> v1, std::vector<double> v2);
};

#endif