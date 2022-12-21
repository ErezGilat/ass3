#include <list>
#include <map>
#include "Knn.h"
#include "DataSet.h"
#include <vector>
#include <algorithm>
using namespace std;
// Constructor 
Knn::Knn(Distance *d,int k, DataSet *ds) {
    this->distance = d;
    this->k = k;
    this->data = ds;
};
// Destructor
Knn::~Knn() {
};
// create a vector of pairs of distances and classifications
vector <pair<double, string> > Knn::createDistancesVector(vector<double> v){
    vector <pair<double, string> > distancesVector;
    int s = data->getDataSet().size();
    for (int i=0;i<s;i++){
        double dis=this->distance->calculateDistance(v,this->data->getDataSet()[i].getCharacteristics());
        string cls=this->data->getDataSet()[i].getClassification();
        distancesVector.emplace_back(dis,cls);
    }
    return distancesVector;
};
// predict the classification of a vector by the k nearest neighbors
string Knn::predict (vector<double> v){
    vector <pair<double, string> > distancesVector=createDistancesVector(v);
    sort(distancesVector.begin(),distancesVector.end());
    map <string,int> m;
    for(int i = 0; i < k; i++) {
        m[distancesVector[i].second]++;
    }
        return max_element(m.begin(), m.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second;
    })->first;
};