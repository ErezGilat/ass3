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
using namespace std;

int main(int size, char** args){
    if(size != 3){
        cout<< "Error, Please Enter correct input" <<endl;
        exit(1);
    }
    char * ipAdress=args[1];
    int portNo=stoi(args[2]);
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock<0){
        perror ("error creating socket");
        exit (1);
    }
    struct sockaddr_in sin;
    memset (&sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ipAdress);
    sin.sin_port = htons(portNo);
    if(connect(sock,(struct sockaddr *)&sin, sizeof(sin))<0){
        perror("error connecting to server");
        exit(1);
    }
    while (true){
        string data;
        getline(cin,data);
        if (data=="-1"){
            break;
        }
        int dataLen = strlen(data.c_str());
        int sentBytes = send (sock, data.c_str(),dataLen,0);
        char buffer[4096];
        memset (&buffer, 0,sizeof(buffer));
        int expectedDataLen = sizeof(buffer);
        int readBytes = recv (sock, buffer, expectedDataLen, 0); 
        if(readBytes==0){
            perror("connection is closed");
            break;
        }
        else if(readBytes < 0){
            perror("error");
            break;
        }
        else {
            cout << buffer;
        }
    }
    close(sock);
    return 0; 
}