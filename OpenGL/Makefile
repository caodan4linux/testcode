CC:=gcc
CFLAGS:=-Iglad/include
LDFLAGS:=-Wl,-rpath=/usr/local/lib64 -ldl -L/usr/local/lib64 -lglfw

all: opengl_test

opengl_test: glad.o opengl_test.o Makefile
	$(CC) $(CFLAGS) -c opengl_test.c
	$(CC) $(CFLAGS) -c glad/src/glad.c
	$(CC) $(LDFLAGS) -o $@ opengl_test.o glad.o
