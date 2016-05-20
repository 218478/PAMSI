#ifndef BRANCH_BOUND_EXTENDED_LIST_TEST_H_
#define BRANCH_BOUND_EXTENDED_LIST_TEST_H_

#include "Graph.h"
#include "IRunnable.h"

#include <iostream>

/*! \brief Test algorytmu branch & bound + extended list z klasy Graf.
*
* \details Ladnie opakowany i czytelny test.
*/
class BranchBoundExtendedListTest : IRunnable {
private:
	/*! \brief Badany graf.
	*/
	Graph graph;
	int start, stop;

public:
	/*! \brief Konstruktor testu branch & bounda + extended list.
	 *
	 * \details	Tutaj tak naprawde odbywa sie konstrukcja obiektu.
	 *		Gdyby operacja ta miala miejsce w metodzie prepare()
	 *		byloby za duzo januszowej sztuki kodowania.
	 */
	BranchBoundExtendedListTest(int how_many) : graph(how_many) {}

	/*! \brief Funkcja, w ktorej nic sie nie dzieje, a mialo.
	 *
	 * \detail Wyjasnienie w konstruktorze.
	 */
	virtual void prepare(int how_many) {
		// do nothing because prepare was done in a constructor
	}

	/*! \brief Odpalamy algorytm.
	*/
	virtual void run() {
		graph.branchBoundExtendedList(start, stop);	
	}
};

#endif  // BRANCH_BOUND_EXTENDED_LIST_TEST_H_