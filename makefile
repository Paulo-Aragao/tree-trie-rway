all:	main.o
	g++ -std=c++11 -o tree main.cpp

main.o:	main.cpp ArvoreRWay.hpp No.hpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -lf*o
