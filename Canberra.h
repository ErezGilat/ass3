#ifndef _CANBERRA_H_
#define _CANBERRA_H_

#include <iostream>
#include <vector>
#include <string>
#include "Distance.h"
// Canberra distance class - inherits from Distance
class Canberra : public Distance {
public:
    Canberra();
    virtual ~Canberra();
    double calculateDistance(std::vector<double> v1, std::vector<double> v2);
};


#endif