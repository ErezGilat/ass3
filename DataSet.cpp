#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "DataSet.h"
#include "ClassifiedVector.h"
#include "distances/Distance.h"
using namespace std;

// Constructor
DataSet::DataSet()
{
    this->set = vector <ClassifiedVector> ();
};
// Destructor
DataSet::~DataSet()
{
};

// get a new classified vector and add it to the set
void DataSet::addClassifiedVector(ClassifiedVector vec)
{
    this->set.push_back(vec);
};

// return the set
vector <ClassifiedVector> DataSet::getDataSet()
{
    return this->set;
};
// return the size of each vector in the set
int DataSet::getVectorsSize ()
{
    return this->set[0].getCharacteristics().size();
}
// read the csv file and create a new classified vector for each row and add it to the set
void DataSet::readCsv(string fileName)
{
    ifstream file(fileName);
    string line;
    vector <double> row;
    string classification;
    int i = 0, last = 0;
    if (file.is_open())
    {
        while (getline(file,line)) {
            stringstream check1(line);
            string intermediate;
            while (getline(check1, intermediate, ','))
            {
                try
                {
                    row.push_back(stod(intermediate));
                }
                catch(...)
                {
                    classification = intermediate;
                }
            }
            i = row.size();
            if (i != last && last != 0)
            {
                cout << "Error: The number of columns in the file is not consistent" << endl;
                exit(1);
            }
            last = i;
            ClassifiedVector *vec = new ClassifiedVector(row, classification);
            this->addClassifiedVector(*vec);
            row.clear();
        }
        file.close();
    } else {
        cout << "Unable to open file";
        exit(1);
    }
};

