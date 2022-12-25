#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Chebyshev.h"
using namespace std;
// Constructor
Chebyshev::Chebyshev() {
};
// Destructor
Chebyshev::~Chebyshev() {
};
// Chebyshev distance
double Chebyshev::calculateDistance(std::vector<double> v1, std::vector<double> v2)
{
    double temp, distance = 0;
    for (int i = 0; i < v1.size(); i++) {
        if(i == 0) {
            distance = abs(v1[i]-v2[i]);
        } else {
            if (distance < abs(v1[i]-v2[i]))
                distance = abs(v1[i]-v2[i]);
        }
    }
    return distance;   
};