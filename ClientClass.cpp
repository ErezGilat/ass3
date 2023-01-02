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

ClientClass::ClientClass(int size, char** args)
{
    if(size != 3){
        cout<< "Error, Please Enter correct input" <<endl;
        exit(1);
    }
    ipAdress=args[1];
    portNo=stoi(args[2]);
    socket(AF_INET,SOCK_STREAM,0);
}

void ClientClass::createSocket()
{
    this->sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock<0){
        perror ("error creating socket");
        exit (1);
    }
    memset (&sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ipAdress);
    sin.sin_port = htons(portNo);
}

void ClientClass::connectToServer()
{
    if(connect(this->sock,(struct sockaddr *)&sin, sizeof(sin))<0){
        perror("error connecting to server");
        exit(1);
    }
}

int ClientClass::write()
{
    getline(cin,data);
    if (data=="-1"){
        return -1;
    }
    int dataLen = strlen(data.c_str());
    int sentBytes = send (sock, data.c_str(),dataLen,0);
    return 0;
}

int ClientClass::read()
{
    char buffer[4096];
    memset (&buffer, 0,sizeof(buffer));
    int expectedDataLen = sizeof(buffer);
    int readBytes = recv (sock, buffer, expectedDataLen, 0); 
    if(readBytes==0){
        perror("connection is closed");
        return -1;
    }
    else if(readBytes < 0){
        perror("error");
        return -1;
    }
    else {
        cout << buffer;
    }
    return 0;
}

void ClientClass::closeClient()
{
    close(sock);
}

ClientClass::~ClientClass()
{

}

