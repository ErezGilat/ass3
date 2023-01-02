#include <iostream> 
#include <vector>
#include <string>
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include "ClientClass.h"
using namespace std;

int main(int size, char** args){
    ClientClass *client = new ClientClass(size, args);
    client->createSocket();
    client->connectToServer();

    while (true)
    {
        if (client->write()==-1)
            break;
        if (client->read()==-1)
            break;
    }
    client->closeClient();
    delete client;
    return 0; 
}