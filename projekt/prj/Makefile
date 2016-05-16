CXXFLAGS = -Iinc -Wall -pedantic -g -std=c++11
CC = g++

SOURCES = src/main.cpp

HEADERS = 

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
	@echo " make            - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make order  - usuwa zbedne pliki tymczasowe z koncowka \"~\""
	@echo " make help    - wyswietla niniejsza informacje"
	@echo
