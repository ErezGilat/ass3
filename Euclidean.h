#ifndef EUCLIDEAN_H_
#define EUCLIDEAN_H_

#include <iostream>
#include <vector>
#include <string>
#include "Minkowski.h"
#include "Distance.h"
class Euclidean : public Distance {
public:
    Euclidean();
    virtual ~Euclidean();
    double calculateDistance(std::vector<double> v1, std::vector<double> v2);
};

#endif