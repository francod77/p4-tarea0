all: main run

obj/A.o: obj/B.o obj/C.o Clases/A.cpp Clases/A.h
	g++ -c Clases/A.cpp -o obj/A.o 

obj/B.o: obj/C.o Clases/B.cpp Clases/B.h
	g++ -c Clases/B.cpp -o obj/B.o

obj/C.o: Clases/C.cpp Clases/C.h
	g++ -c Clases/C.cpp -o obj/C.o 

main: main.cpp obj/A.o obj/B.o obj/C.o
	g++ main.cpp obj/A.o obj/B.o obj/C.o -o main

run: 
	./main.exe

clean: 
	rm obj/A.o obj/B.o obj/C.o main
	
