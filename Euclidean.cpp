#include "Euclidean.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Distance.h"
using namespace std;
// Constructor
Euclidean::Euclidean() {
};
// Destructor
Euclidean::~Euclidean() {
};
// Euclidean distance
double Euclidean::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += pow(v1[i] - v2[i], 2);
    }
    return sqrt(sum);
};