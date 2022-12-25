#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>
#include "ClassifiedVector.h"
#include "distances/Distance.h"
#include "DataSet.h"
// Knn class
class Knn{
    public:
        Knn(Distance* d,int k, DataSet *ds);
        ~Knn();
        std::string predict(std::vector<double> v);
        vector <pair<double,string> > createDistancesVector(vector<double> v);
    private:
        Distance *distance;
        int k;
        vector <double> vec;
        DataSet *data;
};

#endif