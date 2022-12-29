# KNN requests server and client

We are implementing the KNN algorithm with a server!
It works with 5 distance calculation fourmals,
supportingg any csv file that you choose.


## how to use the program
first of all you need to make sure the program is successfully compiled (the guide is down below). 
Then, in order to run the program you will need to write the following commands in the terminal.

### for the server -
```
./server.out FILE_OF_CLASSIFIED.csv PORT

```
FILE_OF_CLASSIFIED.CSV - file in csv format that contains the values and the classifications.

PORT - the port number that you want to use for the sever to listen in.

example:

```
./server.out iris_classified.csv 12345
```
This example will generate a server that implements knn model with the iris_classified.csv data 
with port 12345

### for the client -
```
./client.out IP PORT

```

IP - The ip ot the server
PORT - The port that the server uses

example:

```
./client.out 127.0.0.1 12345

```

This command will generate a connection to a the server with the ip 127.0.0.1 (local host) and port 12345 -
it will actually connect to the server that we launched above.

### how to run inputs on the client - 

When the client was launched sucssesfly and connected to server you are now able to send requests 
and get the KNN classifictaion of a certian vector by using the following command:

```
VECTOR DIS K
```
VECTOR - a vector for classification  - in the follwoing format 'x x x x'.
DIS -  optional distacnce functions MAN - Mannahtan AUC - Euclidean MIN - Minkovsky CHB - Chebychve CAN - Cannabra.
K - the number of neigboors we want to take into consideration.

example:
```
1 2 3 4 AUC 4

```
this line will send a request to the server to predict the value of the vector: 1 2 3 4 with Euclidean 
distance function and 4 neighboors.

## How to compile - 
use one of the following commands -
```
make

```
this will genertate both server.out and client.out

or use

```
	g++ -std=c++11 Server.cpp Minkowski.cpp Manhattan.cpp Knn.cpp GetInput.cpp Euclidean.cpp DataSet.cpp ClassifiedVector.cpp Chebyshev.cpp Canberra.cpp -o server.out

    g++ -std=c++11 Client.cpp -o client.out

```
to genertate server.out and client.outor individually