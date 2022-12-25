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
    // try to use port in args[1]
    // if not, use default port
    int serverPort = 0;
    int k;
    if (size != 3) {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1); 
    }
    try {
        serverPort = stoi(args[1]);
    } catch (exception e) {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(serverPort);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    DataSet *ds = new DataSet();
    // Read the csv file
    ds->readCsv(args[2]);
    while (true) {
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        while (true) {
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                break;
            }
            else if (read_bytes < 0) {
                perror("error reading from client socket");
                break;
            }
            // Pointer to point the word returned by the strtok() function.
            char * p;
            string vec = "";
             // Here, the delimiter is white space.
            p = strtok(buffer, " ");
            Distance *d;
            while (p != NULL) {
                d = getDistanceType(p);
                if(d != NULL) {
                    p = strtok(NULL, " ");
                    break;
                }
                vec = vec + ' ' + p;
                p = strtok(NULL, " ");
            }
            if (p != NULL) {
                k = getK(p);
                if (k == -1) {
                    data = "invalid input";
                }                    
            } else {  // if i get to here it means there is no k or no distance
                data = "invalid input";
                k = -1;
            }
            vector<double> toPredict = getVector(vec, ds->getVectorsSize());
            if (toPredict.size() == 0) {
                data = "invalid input";
            }
            if (k != -1 && toPredict.size() != 0  && d != NULL) {
                Knn knn(d, k, ds);
                data = knn.predict(toPredict);
            } else {
                data = "invalid input";
            }
            int sent_bytes = send(client_sock, data.c_str(), read_bytes, 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
        close(client_sock);
    }
    return 0;
}