#include "Manhattan.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Distance.h"
using namespace std;
// Constructor
Manhattan::Manhattan() {
};
// Destructor
Manhattan::~Manhattan() {
};
// Manhattan distance
double Manhattan::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += abs(v1[i] - v2[i]);
    }
    return sum;
};