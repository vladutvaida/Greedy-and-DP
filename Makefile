CC=g++
CFLAGS=-Wall

build: frati.cpp ursi.cpp planificare.cpp numaratoare.cpp
	$(CC) $(CFLAGS) frati.cpp -o p1.out
	$(CC) $(CFLAGS) ursi.cpp -o p2.out
	$(CC) $(CFLAGS) planificare.cpp -o p3.out
	$(CC) $(CFLAGS) numaratoare.cpp -o p4.out

run-p1:
	./p1.out

run-p2:
	./p2.out

run-p3:
	./p3.out

run-p4:
	./p4.out

clean:
	rm -f p1.out p2.out p3.out p4.out
