// Copyright 2016 Kamil Kuczaj
#ifndef LAB07_18_04_PRJ_INC_BINARYTREE_H_
#define LAB07_18_04_PRJ_INC_BINARYTREE_H_

#include "IBinaryTree.h"
#include "Tablica.h"

/*! \brief Implementacja drzewa binarnego.
 */
template <class Type>
class BinaryTree : IBinaryTree<Type> {
 private:
  /*! \brief Tablica dynamiczna, na ktorej zbudowane jest drzewo.
   *
   * \details Wykorzystuje konstrukcje tablicy dynamicznej, ktora
   *          powieksza swoj rozmiar zawsze dwukrotnie (sprawdzic w metodzie
   *          increaseSize() klasy Array.\
   *          Waznym elementem tej klasy jest fakt, ze lewe dziecko rodzica
   *          w drzewie bedzie mialo zawsze indeks [rodzic*2+1] a to po prawej
   *          [rodzic*2+2]. Tak dzieje sie w moim przypadku, gdyz indeksuje
   *          korzen jako element nr 0.
   */
  Array<Type> tree;

  /*! \brief Przechowuje informacje ile elementow znajduje sie w drzewie.
   *
   * \details Zmienna pomocna przy budowaniu drzewa. Takiej implementacji
   *          nie zapewnila moja tablica dynamiczna.
   */
  int size;

 public:
  /*! \brief Konstruktor.
   *
   * \details Napisanie konstruktora zostalo wymuszone przez wprowadzenie
   *          zmiennej size, ktora przechowuje rozmiar drzewa.
   */
  BinaryTree() : size(0) {}
  /*! \brief Dodaje element do drzewa.
   *
   * \details Dodaje element do drzewa wstawiajac go w odpowiednie
   *          miejsce.
   */
  virtual void put(Type element) {
    if (size == 0) {
      tree[0] = element;
      size++;
    }
  }

  /*! \brief Wyszukuje element w drzewie.
   *
   * \details Wyszukuje element typu Type w drzewie.
   *          Zwraca prawde gdy znajdzie, falsz gdy nie.
   *
   * \param[in] element Szukany element.
   *
   * \retval true Element znajduje sie w drzewie.
   * \retval false Elementu nie ma w drzewie.
   */
  virtual bool search(Type element) const {
    for (int index = 0; index < size;) {
      if (element == tree[index]) {
        return true;
      } else if (element < tree[index]) {
        index = index*2 + 1;  // If the element is on the left side
      } else {
        index = index*2 + 2;  // If the element is on the right side
      }
    }
    return false;
  }

  /*! \brief Porzadkuje drzewo.
   *
   * \details Porzadkuje drzewo w taki sposob, ze mniejsze elementy
   *          od korzenia/rodzica znajduja sie zawsze z lewej strony,
   *          a wieksze po prawej.
   */
  virtual void rebalance() {}

  /*! \brief Wyswietla zawartosc drzewa.
   *
   * \details Wydrukowuje na standardowym wyjsciu zawartosc drzewa.
   *          Kazdy poziom jest drukowany w osobnej linii.
   */
  virtual void print() {
    if (size > 0)
      std::cout << tree[0] << std::endl;
    else
      throw("Empty tree");

    int j = 1;
    for (int i = 1; i < size; i++) {
      std::cout << tree[i] << " ";

      if ((i-(2^(j-1))) == ((2^j)+1)) {
        std::cout << std::endl;
        j++;
      }
    }
  }
};


#endif  // LAB07_18_04_PRJ_INC_BINARYTREE_H_
