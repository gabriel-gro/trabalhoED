CC=g++
CPPFLAGS=-W -Wall

all: tadConjuntos

tadConjuntos: tadConjuntos.o Conjunto.o 
	$(CC) $(CPPFLAGS) -o tadConjuntos tadConjuntos.o Conjunto.o 
		
tadConjuntos.o: tadConjuntos.cpp
	$(CC) $(CPPFLAGS) -o tadConjuntos.o -c tadConjuntos.cpp 
	 
Conjunto.o: Conjunto.cpp Conjunto.h 
	$(CC) $(CPPFLAGS) -o Conjunto.o -c Conjunto.cpp 
		   
clean:
	rm -rf *.o

mrproper: clean
	rm -rf tadConjuntos
