all:
	g++ -Wall -o main src/main.cpp src/matrixEsp.cpp
	clear
	./main
c:
	g++ -Wall -o main src/main.cpp src/matrixEsp.cpp
	./main