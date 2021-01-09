CC = g++ -std=c++11
CFLAGS = -Wall -Wextra
OBJS = src/AbstractHex.cpp src/Cell.cpp main.cpp

muo: 
	$(CC) $(OBJS) $(CFLAGS) -o output
	./output

debug:
	$(CC) $(OBJS) $(CFLAGS) -g -o output
	gdb ./output

memory:
	valgrind ./output