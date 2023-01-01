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

ServerClass::ServerClass(int size, char ** args)
{
    if (size != 3) 
    {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1); 
    }
    try 
    {
        serverPort = stoi(args[2]);
    } 
    catch (exception e) 
    {
        cout << "Error, Please Enter correct input next time" << endl;
        exit(1);
    }
    createSocket();
    bindSocket();
    ds->readCsv(args[1]);
}

void ServerClass::createSocket()
{
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) 
    {
        perror("error creating socket");
        exit (1);
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(serverPort);
}

void ServerClass::bindSocket()
{
    if (bind(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) 
    {
        perror("error binding socket");
        exit (1);
    }
}

void ServerClass::listenToSocket()
{
    if (listen(sock, 5) < 0) 
    {
        perror("error listening to a socket");
        exit(1);
    }
}

int ServerClass::acceptClient()
{
    struct sockaddr_in clientSin;
    unsigned int addrLen = sizeof(clientSin);
    clientSock = accept(this->sock, (struct sockaddr *) &clientSin, &addrLen);
    if (clientSock < 0) {
        perror("error accepting client");
        return -1;
    }
    return 0;
}

int ServerClass::read()
{
    char buffer[4096];
    memset (&buffer, 0,sizeof(buffer));
    int expectedDataLen = sizeof(buffer);
    int readBytes = recv(clientSock, buffer, expectedDataLen, 0);
    if (readBytes == 0) {
        return -1;
    }
    else if (readBytes < 0) {
        perror("error reading from client socket");
        return -1;
    }
    input = string(buffer);
}

void ServerClass::calcData()
{
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
}

int ServerClass::write()
{
    int sentBytes = send(clientSock, data.c_str(), data.size(), 0);
        if (sentBytes < 0) {
            perror("error sending to client");
            return -1;
        }
    return 0;
}

void ServerClass::closeClient ()
{
    close(clientSock);
}
ServerClass::~ServerClass()
{

}