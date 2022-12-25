#ifndef CHEBYSHEV_H
#define CHEBYSHEV_H

#include <iostream>
#include <vector>
#include <string>
#include "Distance.h"
// Chebyshev distance class - inherits from Distance
class Chebyshev : public Distance {
public:
    Chebyshev();
    virtual ~Chebyshev();
    double calculateDistance(std::vector<double> v1, std::vector<double> v2);
};


#endif