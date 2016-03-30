// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_H_
#define LAB03_14_03_PRJ_INC_STOS_H_

#include "IStos.h"
#include "Lista.h"


/*! \brief Implementacja klasy Stos, zlozonej z intow.
 *
 * \details Implementacja pojemnika, gdzie dostepny jest jedynie element
 *          bedacy "na gorze". Jej skladowe elementy to inty. Zdecydowalem
 *          sie nie stosowac szablonow ze wzgledu na niepotrzebna komplikacje.
 *          Nie zdecydowalem sie na uzycie listy jako elementu klasy, poniewaz
 *          stos posiada teraz wlasny interfejs i zmieniajac cos w liscie,
 *          musialbym rowniez kompilowac ten plik jeszcze raz. Poza tym w liscie
 *          dodaje sie slowa, a nie inty.\
 *          Nie ma ograniczen rozmiaru.
 */
class Stos: IStos {
 private:
  /*! \brief Imlementacja wezlow dla stosu.
   *
   * \details Potrzebne do implementacji interfejsu stosu. Zawiera pole
   *          typu string.
   */
  struct Node {
    /*! \brief Element w wezle.
     *
     * \details Co jest w wezle. Ma przechowywac pojedyncza liczbe calkowita.
     */
    int element;

    /*! \brief Wskaznik na nastepny wezel.
     *
     * \details Wskazuje na nastepny wezel.
     */
    Node* next;
  };


  /*! \brief Pierwszy element stosu. Tzw. wierzcholek.
   *
   * \details Wskazuje na pierwszy element listy.
   */
  Node *top;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Inicjalizuje wierzcholek *top jak wskaznik na NULL.
   */
  Stos(): top(0) {}

  /*! \brief Destruktor.
   *
   * \details Popuje wszystkie elementy.
   */
  ~Stos();

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   * \param[in] item "Wpychany" element typu int.
   */
  virtual void push(int item);

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual int pop();

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *          Metoda czysto wirtualna.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty();

  /*! \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku. Metoda czysto wirtualna.
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
