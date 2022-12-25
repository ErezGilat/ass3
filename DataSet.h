#ifndef DATASET_H_
#define DATASET_H_
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "DataSet.h"
#include "ClassifiedVector.h"
#include "distances/Distance.h"
using namespace std;
// DataSet class - holds a vector of ClassifiedVector objects
class DataSet
{
private:
    vector<ClassifiedVector> set;

public:
    DataSet();
    ~DataSet();
    void addClassifiedVector(ClassifiedVector vec);
    vector <ClassifiedVector> getDataSet();
    void readCsv(string filename);
    int getVectorsSize ();
};

#endif