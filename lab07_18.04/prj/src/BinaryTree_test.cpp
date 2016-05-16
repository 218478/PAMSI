// Copyright 2016 Kamil Kuczaj
#include "BinaryTree_test.h"

#include <cstdlib>  // dealing with pseudo random numbers

void BinaryTree_test::prepare(int size) {
  tree = new TRBTree;

  int *Tk = new int(size);          // Tablica kluczy węzłów
  int i,x,i1,i2;
  srand(time(NULL));     // Inicjujemy generator pseudolosowy

  for(i = 0; i < size; i++) // Tablicę wypełniamy wartościami kluczy
    Tk[i] = i + 1;

  int random_index = static_cast<int>(rand()) % size;

  for(i = 0; i < size; i++)  // Mieszamy tablicę
  {
    i1 = rand() % MAXN;     // Losujemy 2 indeksy
    i2 = rand() % MAXN;

    x = Tk[i1];             // Wymieniamy Tk[i1] <-->. Tk[i2]
    Tk[i1] = Tk[i2];
    Tk[i2] = x;

    if (i == random_index)
      random_element = i1;
  }

  for(i = 0; i < size; i++) // Na podstawie tablicy tworzymy drzewo czerwono-czarne
  {
    cout << Tk[i] << " ";
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
