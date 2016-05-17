// Copyright 2016 Kamil Kuczaj
#include "BinaryTree_test.h"

#include <cstdlib>  // dealing with pseudo random numbers
#include <vector>  // to play with a different type of dynamic array
#include <algorithm>  // swap function

void BinaryTree_test::prepare(int MAXN) {
  flag = false;
  tree = new TRBTree;

  std::vector<int> Tk(MAXN);          // Tablica kluczy węzłów
  int i1,i2;
  srand(time(NULL));     // Inicjujemy generator pseudolosowy

  for (int i = 0; i < MAXN; i++) // Tablicę wypełniamy wartościami kluczy
    Tk.push_back(i - MAXN/2);

  int random_index = static_cast<int>(rand()) % MAXN;

  for (int i = 0; i < MAXN*10; i++)  // Mieszamy tablicę
  {
    i1 = rand() % MAXN;     // Losujemy 2 indeksy
    i2 = rand() % MAXN;

    std::swap(Tk[i2],Tk[i1]);

    if (i == random_index)
      random_element = i1;
  }

  for(int i = 0; i < MAXN; i++) // Na podstawie tablicy tworzymy drzewo czerwono-czarne
  {
    // cout << Tk[i] << " ";
    tree->insertRBT(Tk[i]);
  }

}

void BinaryTree_test::run() {
	if (tree->findRBT(random_element) != nullptr)
		flag = true;
	else
		flag = false;


    std::cout << "\nFlaga: " << flag << std::endl << std::endl;

    tree->print();
}
