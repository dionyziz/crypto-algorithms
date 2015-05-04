CC=g++ -c -g
LINK=g++

all: miller_rabin.o bignum.h
	$(LINK) miller_rabin.o

test.o: test.cpp test.h
	$(CC) test.cpp -o test.o

miller_rabin.o: miller_rabin.cpp miller_rabin.h bignum.h
	$(CC) miller_rabin.cpp -o miller_rabin.o

euclid.o: euclid.cpp euclid.h bignum.h
	$(CC) euclid.cpp -o euclid.o

rsa_test.o: rsa_test.cpp test.h miller_rabin.h
	$(CC) rsa_test.cpp -o rsa_test.o

rsa_test: rsa_test.o miller_rabin.o euclid.o test.o
	$(LINK) rsa_test.o miller_rabin.o euclid.o test.o -o rsa_test

rsa.o: rsa.cpp miller_rabin.h euclid.h bignum.h
	$(CC) rsa.cpp -o rsa.o

rsa: rsa.o miller_rabin.o euclid.o
	$(LINK) rsa.o miller_rabin.o euclid.o -o rsa

clean:
	rm *.o
