#include <iostream>
#include <vector>
#include <string>
#include "ClassifiedVector.h"
#include "distances/Distance.h"
using namespace std;
// Constructor
ClassifiedVector::ClassifiedVector(vector<double> v, string s){
    this->characteristics = v;
    this->classificaiton = s;
};
// Destructor
ClassifiedVector::~ClassifiedVector()
{
};
// Getters
// Return the characteristics of the vector
vector<double> ClassifiedVector::getCharacteristics (){
    return characteristics;
};
// Return the classification of the vector
string ClassifiedVector::getClassification (){
    return classificaiton;
};
// Get the distance between this vector and another vector
double ClassifiedVector::getDistance(vector<double> other, Distance * d)
{
    return d->calculateDistance(characteristics,other);
};
