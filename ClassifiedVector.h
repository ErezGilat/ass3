#ifndef CLASSIFIEDVECTOR_H_
#define CLASSIFIEDVECTOR_H_
#include <iostream>
#include <vector>
#include <string>
#include "Distance.h"
using namespace std;

// ClassifiedVector class
class ClassifiedVector
{
private: 
    
    vector<double> characteristics; 

    string classificaiton;   

public:

    ClassifiedVector(vector<double> v, string s);

    ~ClassifiedVector();
    
    vector<double> getCharacteristics();
    
    double getDistance(vector<double> other, Distance * d);
    
    string getClassification ();
};

#endif