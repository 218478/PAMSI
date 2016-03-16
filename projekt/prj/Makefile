CXXFLAGS = -Iinc -Wall -pedantic -g
COMPILER = g++

__start__: program
	./program

program: obj obj/main.o obj/Stoper.o obj/Tablica.o obj/Sedzia.o obj/Stos.o \
	 obj/Kolejka.o obj/Lista.o
	g++ obj/main.o obj/Stoper.o obj/Tablica.o obj/Sedzia.o obj/Stos.o \
	 obj/Kolejka.o obj/Lista.o -o program

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Sedzia.h
	g++ ${CXXFLAGS} -c src/main.cpp -o obj/main.o

obj/Stoper.o: src/Stoper.cpp inc/Stoper.h inc/IStoper.h
	g++ ${CXXFLAGS} -c src/Stoper.cpp -o obj/Stoper.o

obj/Tablica.o: src/Tablica.cpp inc/Tablica.h inc/IRunnable.h
	g++ ${CXXFLAGS} -c src/Tablica.cpp -o obj/Tablica.o

obj/Sedzia.o: src/Sedzia.cpp inc/Sedzia.h inc/Stoper.h inc/Tablica.h \
		inc/Stos.h inc/Kolejka.h inc/Lista.h
	g++ ${CXXFLAGS} -c src/Sedzia.cpp -o obj/Sedzia.o

obj/Stos.o: src/Stos.cpp inc/Stos.h inc/IRunnable.h
	g++ ${CXXFLAGS} -c src/Stos.cpp -o obj/Stos.o

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.h inc/IRunnable.h
	g++ ${CXXFLAGS} -c src/Kolejka.cpp -o obj/Kolejka.o

obj/Lista.o: src/Lista.cpp inc/Lista.h inc/IRunnable.h
	g++ ${CXXFLAGS} -c src/Lista.cpp -o obj/Lista.o


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
