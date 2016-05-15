// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "GraphBFS.h"
#include "GraphDFS.h"

#include <unistd.h>  // to make Linux wait because searching is too fast

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages

void Sedzia::setOffGraphDFS(int& how_many, int& trials_count) {
	GraphDFS dfs(how_many);
	dfs.prepare(how_many);
	std::ostringstream temp_buffer;
	temp_buffer << "DFS_" << how_many;
	std::cout << "Ilosc prob: " << trials_count << std::endl
	<< "Wielkosc proby: " << how_many << std::endl;
	for (int i = 0; i < trials_count; i++) {
		timer.start();
		dfs.run();
		timer.stop();
		timer.dumpToFile(temp_buffer.str());
	}
}

void Sedzia::setOffGraphBFS(int& how_many, int& trials_count) {
	GraphBFS bfs(how_many);
	bfs.prepare(how_many);
	std::ostringstream temp_buffer;
	temp_buffer << "BFS_" << how_many;
	std::cout << "Ilosc prob: " << trials_count << std::endl;
	for (int i = 0; i < trials_count; i++) {
		timer.start();
		bfs.run();
		timer.stop();
		timer.dumpToFile(temp_buffer.str());
	}
}
