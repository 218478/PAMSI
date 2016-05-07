// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "GraphBFS.h"
#include "GraphDFS.h"

#include <unistd.h>  // to make Linux wait because searching is too fast

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages

void Sedzia::setOffGraphDFS(int how_many) {
	GraphDFS dfs;
	dfs.prepare(how_many);
	std::ostringstream temp_buffer;
	temp_buffer << "GraphDFS_" << how_many;
	timer.start();
	dfs.run();
	timer.stop();
	timer.dumpToFile(temp_buffer.str());
}

void Sedzia::setOffGraphBFS(int how_many) {
}
