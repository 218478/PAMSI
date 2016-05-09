// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "BranchBoundTest.h"
#include "BranchBoundExtendedListTest.h"

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages

void Sedzia::setOffGraphBranchBound(int& how_many, int& trials_count) {
	BranchBoundTest obiekt(how_many);
	obiekt.prepare(how_many);
	std::ostringstream temp_buffer;
	temp_buffer << "BB_" << how_many;
	for (int i = 0; i < trials_count; i++) {
		timer.start();
		obiekt.run();
		timer.stop();
		timer.dumpToFile(temp_buffer.str());
	}
}

void Sedzia::setOffGraphBranchBoundExtendedList(int& how_many, int& trials_count) {
	BranchBoundExtendedListTest obiekt(how_many);
	obiekt.prepare(how_many);
	std::ostringstream temp_buffer;
	temp_buffer << "BB_" << how_many;
	for (int i = 0; i < trials_count; i++) {
		timer.start();
		obiekt.run();
		timer.stop();
		timer.dumpToFile(temp_buffer.str());
	}
}
