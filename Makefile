CXX=g++
RM=rm -f
RMD=rm -rf
CPPFLAGS=-g -Wall -std=c++11 # debugging
OFLAGS=-c

O=$(CXX) $(CPPFLAGS) $(OFLAGS) # compile object file
R=$(CXX) $(CPPFLAGS) # compile runnable file

all: testmat testvec

testmat: testmat.o mat.o vec.o
	$R testmat.o mat.o vec.o -o testmat

testmat.o: testmat.cpp mat.o vec.o
	$O testmat.cpp mat.o vec.o

mat.o: mat.cpp mat.h vec.o
	$O mat.cpp vec.o

testvec: testvec.o vec.o
	$R testvec.o vec.o -o testvec

testvec.o: testvec.cpp vec.o
	$O testvec.cpp vec.o

vec.o: vec.cpp vec.h
	$O vec.cpp


.PHONY: clean

clean:
	$(RM) testmat
	$(RM) testvec
	$(RM) *.o
