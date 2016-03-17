#ifndef LISTA_H
#define LISTA_H

#include "IRunnable.h"

/*! \file Lista.h
 *
 * \brief Implementacja dwukierunkowej listy.
 *
 * \details Wskutek zastosowania szablonow wszystkie definicje musza znajdowac
 *          sie w pliku naglowkowym, a nie zrodlowym.
 *
 * \author Kamil Kuczaj.
 */


/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis
 */
typedef unsigned int uint;


/*! \brief Klasa Lista, w ktorej odbywa sie zapis dynamiczny elementow typu int.
 *
 * \details Implementuje metody interfejsu IRunnable. Zajmuje sie dynamiczna
 *          alokacja pamieci.
 */
template <class Type> class Lista: IRunnable {
 private:
  Lista<Type> *Node;
  

 public:
  Type add(Type item, uint index);
  Type remove(uint index);
  bool isEmpty();
  Type get(uint index);
  uint size();

  virtual void run();
  virtual void prepare();

};


#endif
