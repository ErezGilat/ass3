# KNN requests server

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
PORT - the port number that you want to use for the sever to listen in

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
it will actually connect to the server that we launched aboved.

