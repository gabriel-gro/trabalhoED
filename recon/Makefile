CC=g++
CPPFLAGS=-W -Wall

all: recon

recon: recon.o pilha.o 
	$(CC) $(CPPFLAGS) -o recon recon.o pilha.o 
		
recon.o: recon.cpp
	$(CC) $(CPPFLAGS) -o recon.o -c recon.cpp 
	 
pilha.o: pilha.cpp pilha.h 
	$(CC) $(CPPFLAGS) -o pilha.o -c pilha.cpp 
		   
clean:
	rm -rf *.o

mrproper: clean
	rm -rf recon
