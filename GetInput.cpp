#include <iostream>
#include <string>
#include<algorithm>
#include <regex.h>
#include <cassert>
#include <vector>
#include <fstream>
#include "DataSet.h"
#include <sstream>
#include "Distance.h"
#include "Manhattan.h"
#include "Canberra.h"
#include "Euclidean.h"
#include "Minkowski.h"
#include "Chebyshev.h"
#include "DataSet.h"
#include "ClassifiedVector.h"
using namespace std;
/*
    This function checks if the str it gets is proper to the regex pattern which it gets.
    It returns true only if the input match the regex pattern.
*/
bool isItProperInput(const std::string& inputStr, const std::string& pattern) {
    regex_t regex;
    int reti;
    reti = regcomp(&regex, pattern.c_str(), REG_EXTENDED);
    if (reti) {
            fprintf(stderr, "Could not compile regex\n");
            exit(1);
    }
    reti = regexec(&regex, inputStr.c_str(), 0, NULL, 0);
    if (!reti) {
        return true;
    }
    else if (reti == REG_NOMATCH) {
        return false;
    } else {
        //regerror(reti, &regex, NULL, sizeof(inputStr.c_str()));
        fprintf(stderr, "Regex match failed: %s\n", inputStr.c_str());
        return false;
    }
    regfree(&regex);
    return false;
}

int getK(string input) {
    int k;
    std::string ruleStrK = "^[0-9]+(.0+)?$";
    if (isItProperInput(input,ruleStrK)==true){
        k = stoi(input);
    } else {
        return -1;
    }
    return k;
}
// This function gets the distance type from the argument and returns the distance type
Distance *getDistanceType(string input)
{
    Distance *d;
    if(input=="AUC"){
        d = new Euclidean();
    }
    else if(input=="MAN"){
        d = new Manhattan();
    }
    else if(input=="CHB"){
        d = new Chebyshev();
    }
    else if(input=="CAN"){
        d = new Canberra();
    }
    else if(input=="MIN"){
        d = new Minkowski(2);
    }
    else {
        return NULL;
    }
    return d;
}
// This function gets a vector from the user and returns it
vector<double> getVector(string vec, int vectorsSize) {
    std::string ruleStrVec = "^[0-9]*(.[0-9]+)?( [0-9]*(.[0-9]+)?)*$";
    if (isItProperInput(vec, ruleStrVec) == false) {
        return vector<double>();
    }
    std::vector <double> finalVector;
    std::stringstream check1(vec);
    std::string intermediate;
    while (std::getline(check1, intermediate, ' '))
    {
        try
        {
            finalVector.push_back(std::stod(intermediate));
        }
        catch(const std::exception& e)
        {
            return vector<double>();
        }
    }
    if (finalVector.size()!=vectorsSize){
        return vector<double>();
    }
    return finalVector;
}
