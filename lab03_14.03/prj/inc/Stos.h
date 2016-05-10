// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_H_
#define LAB03_14_03_PRJ_INC_STOS_H_

#include "IStos.h"
#include "Lista.h"

#include <string>

/*! \brief Implementacja klasy Stos, zlozonej z intow.
 *
 * \details Implementacja pojemnika, gdzie dostepny jest jedynie element
 *          bedacy "na gorze". Jej skladowe elementy to stringi. Zdecydowalem
 *          sie nie stosowac szablonow ze wzgledu na niepotrzebna komplikacje.
 *          Zdecydowalem sie na uzycie listy jako elementu klasy, poniewaz
 *          byl to wymog prowadzacego. Nie ma ograniczen rozmiaru.
 */
class Stos: IStos {
 private:
  /*! \brief Zawartosc stosu.
   *
   * \details Implementacja listy jako pole stosu jest wymogiem prowadzacego.
   *          Dodatkowo bardzo ulatiwa implementacje.
   */
  Lista<std::string> stack;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Inicjalizuje wierzcholek *top jak wskaznik na NULL.
   */
  Stos();

  /*! \brief Destruktor.
   *
   * \details Popuje wszystkie elementy.
   */
  ~Stos();

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   * \param[in] item "Wpychany" element typu std::string.
   */
  virtual void push(std::string item);

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *
   * \return Usuniety element.
   */
  virtual std::string pop();

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty();

  /*! \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size();

  /*! \brief Wyswietla elementy stosu.
   *
   * \details Wyswietla cala zawartosc stosu. Nie jest czescia interfesju.
   */
  void print();
};



#endif  // LAB03_14_03_PRJ_INC_STOS_H_
