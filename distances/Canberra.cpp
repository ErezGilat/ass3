#include "Canberra.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
// Constructor
Canberra::Canberra() {
};
// Destructor
Canberra::~Canberra() {
};
// Canberra distance
double Canberra::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += abs((v1[i] - v2[i])) / (abs(v1[i]) + abs(v2[i]));
    }
    return sum;
};