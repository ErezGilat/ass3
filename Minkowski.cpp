#include "Minkowski.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Distance.h"
using namespace std;
// Constructor
Minkowski::Minkowski(double p) {
    this->p = p;
};
// Destructor
Minkowski::~Minkowski() {
};
// Minkowski distance
double Minkowski::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += pow(abs(v1[i] - v2[i]), p);
    }
    return pow(sum, 1/p);
};
