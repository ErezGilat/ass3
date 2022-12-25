#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <vector>
#include "Distance.h"
using namespace std;

bool isItProperInput(const std::string& inputStr, const std::string& pattern);

double getP ();

Distance *getDistanceType(string input);

int getK(string input);

std::vector<double> getVector(string vec, int vectorsSize);

#endif