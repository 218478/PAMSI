CXXFLAGS = -Iinc -Wall -pedantic -g
CC = g++
SOURCES = src/main.cpp src/Stoper.cpp src/Sedzia.cpp src/Tablica.cpp src/Stos.cpp \
	src/Kolejka.cpp src/Lista.cpp
HEADERS = inc/Stoper.h inc/Sedzia.h inc/Tablica.h inc/Stos.h \
	inc/Kolejka.h inc/Lista.h inc/IRunnable.h inc/IStoper.h inc/IPojemnik.h
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
