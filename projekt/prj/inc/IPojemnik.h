#ifndef IPOJEMNIK_H
#define IPOJEMNIK_H

/*! \file IPojemnik.h
 *
 * \brief Plik zawiera interfejs dla pojemnika Stos, Kolejka oraz Tablica.
 *
 * \details Wskutek zastosowania szablonow wszystkie definicje musza znajdowac
 *          sie w pliku naglowkowym, a nie zrodlowym.
 *
 * \author Kamil Kuczaj.
 */


/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis.
 */
typedef unsigned int uint;


/*! \brief Interfejs dla każdego pojemnika.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
template <class Type> class Pojemnik {
  protected:

  /*! \brief Dodaje element w okreslonym miejscu.
   *
   * \details Metoda czysto wirtualna. Dodaje element item w miejscu index
   *          pojemnika.
   *
   * \param[in] item    Dana, ktora ma byc wlozona.
   * \param[in] index   Indeks, w ktorym ma znalezc sie nowa dana.
   */
  virtual Type add(Type item, uint index);

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   * \param[in] index   Indeks,z ktorego ma zostac usunieta dana.
   */
  virtual Type push(uint index);

  /*!
  virtual bool empty();
  virtual Type pop(uint index);
  virtual uint size();
};


#endif
