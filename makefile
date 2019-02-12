proj7: airport.o main.o
		g++ -o proj7 airport.o main.o

airport.o: airport.cpp myClass.h
		g++ -c airport.cpp
main.o: main.cpp myClass.h
		g++ -c main.cpp

clean:
		rm proj6 airport.o main.o