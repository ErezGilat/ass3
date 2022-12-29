#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <cmath>
#include "Distance.h"
#include "Manhattan.h"
#include "Canberra.h"
#include "Euclidean.h"
#include "Minkowski.h"
#include "Chebyshev.h"
#include "DataSet.h"
#include "ClassifiedVector.h"
#include "Knn.h"
#include "GetInput.h"
using namespace std;
// Main function
int main (int size, char ** args) {
    string data;
    // try to use port in args[2]
    // if not, use default port
    int serverPort = 0;
    if (size != 3) {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1); 
    }
    try {
        serverPort = stoi(args[2]);
    } catch (exception e) {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit (1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(serverPort);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit (1);
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        exit(1);
    }
    DataSet *ds = new DataSet();
    // Read the csv file
    ds->readCsv(args[1]);
    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }
        while (true) {
            char buffer[4096];
            memset (&buffer, 0,sizeof(buffer));
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                break;
            }
            else if (read_bytes < 0) {
                perror("error reading from client socket");
                break;
            }
            string input = string(buffer);
            vector <string> distancesStr = {"MAN","AUC","CHB","MIN","CAN"};
            for (int i=0;i<5;i++){
                size_t loc = input.find(distancesStr[i],0);
                if (loc!=-1&&loc!=0&&loc+4<input.length()){
                    string vecToCheck = input.substr(0,loc-1);
                    vector<double> vecToPredict=getVector (vecToCheck, ds->getVectorsSize());
                    string disTocheck = input.substr(loc,3);
                    Distance *disToPredict = getDistanceType(disTocheck);
                    string kToCheck = input.substr(loc+4);
                    int kToPredict = getK (kToCheck);
                    if (vecToPredict.empty()==true||disToPredict==NULL||kToPredict==-1){
                        data = "invalid input";
                    }
                    else{
                        if (kToPredict>ds->getDataSet().size()){
                            data = "invalid input";
                        }
                        else{
                            Knn knn(disToPredict, kToPredict, ds);
                            data = knn.predict(vecToPredict);
                        }                       
                    }
                    break;
                }
                else {
                    data = "invalid input";
                }
            }
            data+="\n";
            int sent_bytes = send(client_sock, data.c_str(), data.size(), 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
        close(client_sock);
    }
    return 0;
}
