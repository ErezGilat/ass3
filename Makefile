compile:
	g++ -std=c++11 Client.cpp -o client.out
	g++ -std=c++11 Server.cpp Minkowski.cpp Manhattan.cpp Knn.cpp GetInput.cpp Euclidean.cpp DataSet.cpp ClassifiedVector.cpp Chebyshev.cpp Canberra.cpp -o server.out