CXXFLAGS = -Iinc -Wall -pedantic -g -std=c++11
COMPILER = g++

__start__: program
	./program

program: obj obj/main.o obj/pojemnik.o
	g++ obj/main.o obj/pojemnik.o -o program

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/pojemnik.h
	g++ ${CXXFLAGS} -c src/main.cpp -o obj/main.o

obj/pojemnik.o: src/pojemnik.cpp inc/pojemnik.h
	g++ ${CXXFLAGS} -c src/pojemnik.cpp -o obj/pojemnik.o

clean:
	rm -f obj/* program

order:
	rm -f src/*~ inc/*~ *~ src/#* inc/#*

help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo " make order  - usuwa zbedne pliki tymczasowe z koncowka \"~\""
	@echo
