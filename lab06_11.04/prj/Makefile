CXXFLAGS = -Iinc -Wall -pedantic -g -std=c++11
CC = g++
SOURCES = src/main.cpp src/Stoper.cpp src/Sedzia.cpp src/Tablica.cpp \
	src/Stos.cpp src/Kolejka.cpp src/Lista.cpp src/Tablica_test.cpp \
	src/Stos_test.cpp src/Kolejka_test.cpp src/Lista_test.cpp \
	src/HashTable.cpp src/HashTable_test.cpp
HEADERS = inc/Stoper.h inc/Sedzia.h inc/Tablica.h inc/Stos.h inc/Kolejka.h \
	inc/ILista.h inc/Lista.h inc/IRunnable.h inc/IStoper.h inc/ITablica.h \
	inc/IStos.h inc/IKolejka.h  inc/Tablica_test.h inc/Stos_test.h \
	inc/Kolejka_test.h inc/Lista_test.h inc/IHashTable.h inc/HashTable.h \
	inc/HashTable_test.h
OBJECTS = $(subst src/,obj/,$(subst .cpp,.o,$(SOURCES)))
EXECUTABLE = program

__start__: $(EXECUTABLE)
	./$(EXECUTABLE)

all: executable

obj:
	mkdir obj

executable: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

obj/%.o: src/%.cpp $(HEADERS) obj
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

order:
	rm -f src/*~ inc/*~ *~ src/#* inc/#*

help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make order  - usuwa zbedne pliki tymczasowe z koncowka \"~\""
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
