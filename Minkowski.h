#ifndef MINKOWSKI_H_
#define MINKOWSKI_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Distance.h"
// Minkowski distance class - inherits from Distance
class Minkowski : public Distance {
public:
    double p;
    Minkowski(double p);
    virtual ~Minkowski();
    double calculateDistance(std::vector<double> v1, std::vector<double> v2);
};

#endif
