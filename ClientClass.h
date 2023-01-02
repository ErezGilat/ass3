#ifndef CLIENTCLASS_H_
#define CLIENTCLASS_H_
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
#include "ClientClass.h"
using namespace std;

class ClientClass
{
    private:
    char * ipAdress={};
    int portNo=0;
    int sock = 0;
    struct sockaddr_in sin;
    string data="";

    public:
    ClientClass(int size, char** args);
    void createSocket();
    void connectToServer();
    int write();
    int read();
    void closeClient();
    ~ClientClass();
};

#endif