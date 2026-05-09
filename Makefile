CFLAGS = -Wall -Werror -Wextra -lraylib -lGL -lm -lpthread -ldl -lX11
HEADERS =   
OBJECTS =    


all: bin/main.o bin/paint.o bin/movements.o bin/stringutils.o
	gcc $^ -o bin/sCrib ${HEADERS} ${CFLAGS} 

bin/stringutils.o: HEADERS += src/stringutils.h 
bin/stringutils.o: OBJECTS += bin/stringutils.o 
bin/stringutils.o: src/stringutils.c
	mkdir -p bin
	gcc -c src/stringutils.c ${CFLAGS} -o $@

bin/paint.o: HEADERS += src/paint.h 
bin/paint.o: OBJECTS += bin/paint.o.o 
bin/paint.o: src/paint.c
	mkdir -p bin
	gcc -c src/paint.c ${CFLAGS} -o $@

bin/movements.o: HEADERS += src/movements.h 
bin/movements.o: OBJECTS += bin/movements.o 
bin/movements.o: src/movements.c 
	mkdir -p bin
	gcc -c src/movements.c ${CFLAGS} -o $@


bin/main.o: src/main.c
	mkdir -p bin
	gcc -c src/main.c ${CFLAGS} -o $@

clean: 
	rm bin/*
