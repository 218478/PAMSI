// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_H_
#define LAB03_14_03_PRJ_INC_STOS_H_

#include "IStos.h"
#include "Lista.h"



/*! \brief Implementacja klasy Stos, zlozonej z intow.
 *
 * \details Implementacja pojemnika, gdzie dostepny jest jedynie element
 *          bedacy "na gorze". Jej skladowe elementy to stringi. Zdecydowalem
 *          sie nie stosowac szablonow ze wzgledu na niepotrzebna komplikacje.
 *          Zdecydowalem sie na uzycie listy jako elementu klasy, poniewaz
 *          byl to wymog prowadzacego. Nie ma ograniczen rozmiaru.
 */
template <class Type>
class Stos: IStos<Type> {
 private:
  /*! \brief Zawartosc stosu.
   *
   * \details Implementacja listy jako pole stosu jest wymogiem prowadzacego.
   *          Dodatkowo bardzo ulatiwa implementacje.
   */
  Lista<Type> stack;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Inicjalizuje wierzcholek *top jak wskaznik na NULL.
   */
  Stos(): stack() {}

  /*! \brief Destruktor.
   *
   * \details Popuje wszystkie elementy.
   */
  ~Stos() {
    while (!stack.isEmpty())  // while stack is not empty
      pop();
  }

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   * \param[in] item "Wpychany" element typu std::string.
   */
  virtual void push(Type item) { stack.add(item, 0); }

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *
   * \return Usuniety element.
   */
  virtual std::string pop() { return stack.remove(0); }

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty() { return stack.isEmpty(); }

  /*! \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size() { return stack.size(); }

  /*! \brief Wyswietla elementy stosu.
   *
   * \details Wyswietla cala zawartosc stosu. Nie jest czescia interfesju.
   */
  void print() { stack.print(); }
};



#endif  // LAB03_14_03_PRJ_INC_STOS_H_
