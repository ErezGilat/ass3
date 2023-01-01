#ifndef SERVERCLASS_H_
#define SERVERCLASS_H_

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

class ServerClass
{
private:
    int serverPort = 0;
    DataSet *ds = new DataSet();
    struct sockaddr_in sin;
    int sock=0;
    string input="";
    string data;
    int clientSock=0;
public:
    ServerClass(int size, char ** args);
    void createSocket();
    void bindSocket();
    void listenToSocket();
    int acceptClient();
    int read();
    void calcData();
    int write();
    void closeClient();
    ~ServerClass();
};


# endif