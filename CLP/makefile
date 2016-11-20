
CC=g++
CPPFLAGS=-W -Wall

all: CLPmain

CLPmain: CLPmain.o CLP.o 
    $(CC) $(CPPFLAGS) -o CLPmain CLPmain.o CLP.o 
        
CLPmain.o: CLPmain.cpp
    $(CC) $(CPPFLAGS) -o CLPmain.o -c CLPmain.cpp 
    
CLP.o: CLP.cpp CLP.h 
    $(CC) $(CPPFLAGS) -o CLP.o -c CLP.cpp 
        
clean:
    rm -rf *.o

mrproper: clean
    rm -rf CLPmain
