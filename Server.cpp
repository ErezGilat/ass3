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
#include "ServerClass.h"
using namespace std;

// Main function
int main (int size, char ** args) {
    ServerClass *server = new ServerClass(size, args);
    server->listenToSocket();
    while(true)
    {
        if (server->acceptClient()==-1)
            continue;
        while(true)
        {
            if(server->read()==-1)
                break;
            server->calcData();
            if(server->write()==-1)
                break;
        }
        server->closeClient();
    }
    delete server;
    return 0;
}