#makefile

#Makefile
CXX = g++


searchandsort: main.o readFile.o
	${CXX} main.o readFile.o -o searchandsort

main.o: main.cpp
	${CXX} -c main.cpp

readFile.o: readFile.cpp
	${CXX} -c readFile.cpp

clean:
	rm *.o searchandsort
