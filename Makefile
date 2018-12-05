CXX=g++
RM=rm -f
RMD=rm -rf
CPPFLAGS=-g -Wall -std=c++11 # debugging
OFLAGS=-c

O=$(CXX) $(CPPFLAGS) $(OFLAGS) # compile object file
R=$(CXX) $(CPPFLAGS) # compile runnable file

all: testmat testvec testdirect testqr testopt testeig

testeig: testeig.o eig.o mat.o vec.o
	$R testeig.o eig.o mat.o vec.o -o testeig

testeig.o: testeig.cpp eig.o mat.o vec.o
	$O testeig.cpp eig.o mat.o vec.o

eig.o: qr.cpp eig.h mat.o vec.o
	$O eig.cpp mat.o vec.o

testopt: testopt.o opt.o mat.o vec.o direct.o
	$R testopt.o opt.o mat.o vec.o direct.o -o testopt

testopt.o: testopt.cpp opt.o mat.o vec.o direct.o
	$O testopt.cpp opt.o mat.o vec.o direct.o

opt.o: opt.cpp opt.h mat.o vec.o
	$O opt.cpp mat.o vec.o

testqr: testqr.o qr.o mat.o vec.o
	$R testqr.o qr.o mat.o vec.o -o testqr

testqr.o: testqr.cpp qr.o mat.o vec.o
	$O testqr.cpp qr.o mat.o vec.o

qr.o: qr.cpp qr.h mat.o vec.o
	$O qr.cpp mat.o vec.o

testdirect: testdirect.o direct.o mat.o vec.o
	$R testdirect.o direct.o mat.o vec.o -o testdirect

testdirect.o: testdirect.cpp direct.o mat.o vec.o
	$O testdirect.cpp direct.o mat.o vec.o

direct.o: direct.cpp direct.h mat.o vec.o
	$O direct.cpp mat.o vec.o

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
	$(RM) testeig
	$(RM) testopt
	$(RM) testqr
	$(RM) testdirect
	$(RM) testmat
	$(RM) testvec
	$(RM) *.o
