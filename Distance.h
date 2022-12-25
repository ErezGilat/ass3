#ifndef DISTANCE_H_
#define DISTANCE_H_
#include <iostream>
#include <vector>
using namespace std;
// Abstract class for distance
class Distance
{
    public:
        virtual ~Distance() {};
        virtual double calculateDistance(vector<double> v1,vector<double> v2){
            return 0;
        }
};

#endif