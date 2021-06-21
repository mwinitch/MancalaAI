main: main.o MancalaBoard.o Simulate.o
	g++ -o main main.o MancalaBoard.o Simulate.o

Simulate.o: Simulate.cpp Simulate.h
	g++ -c Simulate.cpp

MancalaBoard.o: MancalaBoard.cpp MancalaBoard.h
	g++ -c MancalaBoard.cpp

clean:
	rm -f main main.o Simulate.o MancalaBoard.o