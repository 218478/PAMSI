#ifndef BRANCH_BOUND_TEST_H_
#define BRANCH_BOUND_TEST_H_

#include "Graph.h"
#include "IRunnable.h"
#include "Lista.h"

#include <iostream>

/*! \brief Test algorytmu branch & bound z klasy Graf.
*
* \details Ladnie opakowany i czytelny test.
*/
class BranchBoundTest : public IRunnable{
private:
	/*! \brief Badany graf.
	*/
	Graph graph;
	int start, stop;
	Lista temp;

public:
	/*! \brief Konstruktor testu branch & bounda.
	 *
	 * \details	Tutaj tak naprawde odbywa sie konstrukcja obiektu.
	 *		Gdyby operacja ta miala miejsce w metodzie prepare()
	 *		byloby za duzo januszowej sztuki kodowania.
	 */
	BranchBoundTest(int how_many, int x, int y) :
	graph(how_many), start(x), stop(y), temp() {}

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
		temp = graph.branchBound(start, stop);
		std::cout << "Wynik: " << temp << std::endl;
	}
};

#endif  // BRANCH_BOUND_TEST_H_