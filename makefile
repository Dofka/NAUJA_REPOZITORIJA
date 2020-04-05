main: header.o
	g++ -o main main.cpp header.o

header:
	g++ -c header.cpp

clean:
	rm *.o main
