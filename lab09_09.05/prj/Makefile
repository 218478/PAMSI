CXXFLAGS = -Iinc -Wall -pedantic -g -std=c++11 -Wno-sign-compare
CC = g++

SOURCES = src/main.cpp src/Stoper.cpp src/Sedzia.cpp	src/Lista.cpp src/Graph.cpp \
	src/BranchBoundTest.cpp src/BranchBoundExtendedListTest.cpp

HEADERS = inc/Stoper.h inc/Sedzia.h inc/ILista.h inc/Lista.h \
	inc/IRunnable.h inc/IStoper.h inc/Graph.h inc/IGraph.h \
	inc/BranchBoundTest.h inc/BranchBoundExtendedListTest.h
	
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
