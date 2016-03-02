CXXFLAGS=-g -Wall -pedantic
COMPILER=g++
PROGNAME=program


__start__: ${PROGNAME}
	./${PROGNAME}

${PROGNAME}: obj obj/storage_class.o obj/main.o 
	${COMPILER} ${CXXFLAGS} -o ${PROGNAME} obj/main.o obj/storage_class.o

obj:
	mkdir obj

obj/storage_class.o: src/storage_class.cpp inc/storage_class.h
	 ${COMPILER} ${CXXFLAGS} -c src/storage_class.cpp -o obj/storage_class.o

obj/main.o: src/main.cpp inc/storage_class.h
	 ${COMPILER} ${CXXFLAGS} -c src/main.cpp -o obj/main.o

clean:
	rm -i obj/*.o a.out

