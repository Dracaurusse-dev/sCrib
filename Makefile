CFLAGS = -Wall -Werror -Wextra -lraylib -lGL -lm -lpthread -ldl -lX11


all: bin/main.o
	gcc bin/main.o ${CFLAGS} -o bin/sCrib

bin/main.o: src/main.c
	mkdir -p bin
	gcc -c src/main.c ${CFLAGS} -o bin/main.o
