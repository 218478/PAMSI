// Copyright 2016 Kamil Kuczaj
#ifndef LAB07_18_04_PRJ_INC_IBINARYTREE_H_
#define LAB07_18_04_PRJ_INC_IBINARYTREE_H_

/*! \brief Interfejs drzewa binarnego.
 *
 * \details Zawiera ogolne zalozenia tej struktury danych.
 *          Uzyto szablonow. W przypadku wrzucenia dwoch takich
 *          samych elementow - nadpisuja sie.
 */
template <class Type>
class IBinaryTree {
 public:
  /*! \brief Dodaje element do drzewa.
   *
   * \details Dodaje element do drzewa wstawiajac go w odpowiednie
   *          miejsce.
   */
  virtual void put(Type element) = 0;

  virtual Type operator[] (Type element) const = 0;
};


#endif  // LAB07_18_04_PRJ_INC_IBINARYTREE_H_
