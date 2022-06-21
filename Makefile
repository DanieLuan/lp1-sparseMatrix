all:
	g++ -Wall -o main src/main.cpp src/matrixEsp.cpp test/tests.cpp
	clear
	./main
c:
	g++ -Wall -o main src/main.cpp src/matrixEsp.cpp test/tests.cpp
	./main