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
   *          w drzewie bedzie mialo zawsze indeks [rodzic*2] a to po prawej
   *          [rodzic*2+1].
   */
  Array<Type> tree;

 public:
  /*! \brief Dodaje element do drzewa.
   *
   * \details Dodaje element do drzewa wstawiajac go w odpowiednie
   *          miejsce.
   */
  virtual void put(Type element) {
    
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
  virtual bool search(Type element) const {}

  /*! \brief Porzadkuje drzewo.
   *
   * \details Porzadkuje drzewo w taki sposob, ze mniejsze elementy
   *          od korzenia/rodzica znajduja sie zawsze z lewej strony,
   *          a wieksze po prawej.
   */
  virtual void rebalance() {}
};


#endif  // LAB07_18_04_PRJ_INC_BINARYTREE_H_
