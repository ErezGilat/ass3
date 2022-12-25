#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "distances/Distance.h"
#include "distances/Manhattan.h"
#include "distances/Canberra.h"
#include "distances/Euclidean.h"
#include "distances/Minkowski.h"
#include "distances/Chebyshev.h"
#include "DataSet.h"
#include "ClassifiedVector.h"
#include "Knn.h"
#include "GetInput.h"
using namespace std;
// Main function
int main(int size, char** args) {
    // Check if the input is valid
    if(size != 4){
        cout<< "Error, Please Enter correct input" <<endl;
        exit(1);
    }
    // Create a new DataSet
    DataSet *ds = new DataSet();
    // Get the k value
    int k = getK(args[1]);
    // Read the csv file
    ds->readCsv(args[2]);
    // Get the distance type from the argumant
    Distance *d = getDistanceType(args[3]);
    // Create a new Knn model with the given distance type, k and dataset
    Knn model(d, k,ds);
    vector <double> v;
    // Check if the k value is valid (k <= number of vectors in the dataset)
    if (k > ds->getDataSet().size()) {
        cout << "Invalid k" << endl;
        exit(1);
    }
    // Get a new vector from the user and predict its classification
    while(true) {
        v = getVector(ds->getVectorsSize());
        cout << model.predict(v) << endl;
    }
    return 0;
}