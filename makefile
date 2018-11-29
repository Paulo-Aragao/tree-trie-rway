 output: main.o trie.o
        g++ -std=c++0x -Wall main.o -o output

 main.o: main.cpp No.hpp ArvoreRWay.hpp
        g++ -c main.cpp

 clean:
        rm *.o output