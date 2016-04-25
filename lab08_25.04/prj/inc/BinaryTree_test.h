// Copyright 2016 Kamil Kuczaj
#ifndef LAB07_18_04_PRJ_INC_BINARYTREE_TEST_H_
#define LAB07_18_04_PRJ_INC_BINARYTREE_TEST_H_

#include "IRunnable.h"
#include "RBTree.h"

class BinaryTree_test : virtual IRunnable {
 private:
  /*! \brief Testowane drzewo.
   *
   * \details Pojemnik, ktory jest testowany przez te klase.
   */
  RBtree<int> tree;

  /*! \brief Szukany element.
   *
   * \details Zapisuje szukany element. Dzieki temu bedziemy ciagle mierzyc ten
   *          sam czas i testy beda bardziej wiarygodne.
   */
  int random_element;

 public:
  /*! \brief Przygotowuje pojemnik przed wykonaniem czynnosci.
   *
   * \details Funkcja, ktora ma wykonac wszystkie dodatkowe czynnosci,
   *          ktorych czasu nie bedziemy mierzyc. Polega ona na
   *          wczytaniu konkretnej ilosci elementow.
   *
   * \param[in] size Ilosc elementow.
   */
  virtual void prepare(int size);

  /*! \brief Odpalenie badanej czynnosci.
   *
   * \details Funkcja, ktorej cialem maja byc instrukcje, ktorych czas
   *          chcemy zmierzyc.
   */
  virtual void run();
};


#endif  // LAB07_18_04_PRJ_INC_BINARYTREE_TEST_H_
