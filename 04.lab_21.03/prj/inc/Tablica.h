#ifndef TABLICA_H
#define TABLICA_H

#include "IRunnable.h"

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu
#include <fstream> // to deal with file streams

/*! \file Tablica.h
 *
 * \brief Implementacja interfesju IRunnable.
 *
 * \author Kamil Kuczaj
 */

/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis
 */
typedef unsigned int uint;

/*! \brief Klasa Tablica, w ktorej odbywa sie zapis dynamiczny elementow.
 *
 * \details Implementuje metody interfejsu IRunnable. Zajmuje sie dynamiczna
 *          alokacja pamieci. Elastyczna a propos typow wskutek zastosowania
 *          szablonow.
 */
template <class Type> class Tablica: IRunnable  {
 private:
  /*! \brief Wskaznik do poczatku tablicy dynamicznej.
   *
   * \details Wskazuje na adres w pamieci sterty. Pole prywatne.
   */
  Type *elements;

  /*! \brief Okresla aktualny rozmiar stosu.
   *
   * \details Pole prywatne typu unsigned int, gdyz rozmiar nigdy nie
   *          powinien byc ujemny.
   */
  uint current_size;

  /*! \brief Okresla pozadany rozmiar stosu.
   *
   * \details Pole prywatne typu unsigned int, gdyz rozmiar nigdy nie
   *          powinien byc ujemny. Zadawane w funkcji prepare().
   */
  uint desired_size;

  /*! \brief Okresla aktualny indeks.
   *
   * \details Pole prywatne typu unsigned int, gdyz indeks nigdy nie
   *          powinien byc ujemny. Przechowuje indeks, pierwszej wolnej
   *          komorki pamieci, do ktorego mozliwy bedzie zapis.
   */
  unsigned int index;
  
  /*! \brief Pozwala prosto okreslic, czy nalezy przydzielic pamiec.
   *
   * \details Metoda prywatna. Sluzy do okreslania czy nalezy wywolac
   *          metode increaseSize().
   * 
   * \return true Pamiec pelna. Nalezy zwiekszyc rozmiar.
   *
   * \return false Jest jeszcze wolne miejsce.
   */
  bool isFull() { return ((index >= (current_size)) ?true:false); }

  /*! \brief Zwieksza rozmiar przydzielonej pamieci na stercie.
   *
   * \details Metoda prywatna. Kopiuje elementy starej pamieci do
   *          komorki z nowo-przydzielona pamiecia. Usuwa stara
   *          pamiec.
   */
  void increaseSize() {
    uint new_size = current_size * 2;
    try {
      int *new_elements = new int[new_size];
      for(uint i=0; i < current_size; i++)
	new_elements[i] = elements[i];

      delete [] elements;
      current_size = new_size;
      elements = new_elements;
    }
    // if you fail to allocate memory
    catch (std::bad_alloc& ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

 public:

  /*! \brief Konstruktor parametryczny.
   *
   * \details Umozliwia okreslenie poczatkowego rozmiaru tablicy. W przypadku
   *          braku okreslenia tego rozmiaru przyjmuje domyslna wartosc rowna 10.
   *
   * \param x Okresla poczatkowa wielkosc przydzielonej pamieci. Domyslna wartosc
   *          w przypadku braku podania to 10.
   */
  Tablica(uint x=10) { elements=new int[x]; current_size=x; index=0; }

  /*! \brief Destruktor.
   *
   * \details Usuwa pamiec przypisana komorce, na ktora wskazuje pole *elements.
   */
  ~Tablica() { delete [] elements; }

  /*! \brief Implementacja funkcji prepare() interfesju IRunnable.
   *
   * \details Zapisuje pozadany rozmiar do pola desired_size.
   *
   * \param size Parametr typu unsigned int, gdyz rozmiar nie powinien nigdy byc
   *             ujemny. Jego wartosc zapisywana jest do pola desired_size.
   */
  virtual void prepare (uint size) { desired_size = size; }

  /*! \brief Implementacja funkcji run() interfesju IRunnable.
   *
   * \details Uruchamia "bieg", w ktorym nastepuje zapis elementow do poszczegolnych
   *          elementow tablicy dynamicznej. Tam odbywa sie alokacja pamieci oraz
   *          instrukcje warunkowe.
   */
  virtual void run() {
    while(index < desired_size) {
      if(isFull())
	increaseSize();

      elements[index++] = 123;
    }
  }

  /*! \brief Zwraca aktualny rozmiar tablicy dynamicznej.
   *
   * \details Zwraca wartosc pola current_size.
   *
   * \return Zwraca wartosc typu unsigned int, gdyz takiego typu jest zmienna
   *         current_size.
   */
  uint getSize() { return current_size; }

  /*! \brief Wypisuje zawartosc tablicy
   *
   * \details
   */
  void print() {
    for(int i=0; i < getSize(); i++) { std::cout << elements[i] << std::endl;} }

  /*! \brief Sortowanie babelkowe.
   *
   * \details Przykladowy argument bubble sort. Losowe liczby calkowite
   *          znajduja sie w pliku random_int_list.txt w tym samym folderze
   *          co plik wykonywalny. Nastepnie wyswietla liste.
   */
  void bubbleSort(int how_many);
};


template<class Type> void Tablica<Type>::bubbleSort(int how_many) {
  std::fstream random_int_list;
  random_int_list.open("random_int_list.txt",std::fstream::in);
  try {
    random_int_list.exceptions(random_int_list.failbit);
  }
  catch(const std::ios_base::failure & ex) {
    std::cerr << "Error! Couldn't find or open a file" << ex.what() << std::endl;
  }

  // 100 is the max size of the random ints in a file
  if(how_many > 100)
    throw("There are only 100 ints in the file");

  // read input only if the list is empty and file stream is open
  if(random_int_list.is_open() ) {
    // http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
    // user Wilhelmtell '08
    Type word;
    for(uint i=0; i < how_many; i++) {
      random_int_list >> word;

      if(random_int_list.eof()) break;
      if(isFull())
	increaseSize();
      elements[index++] = word;

    }
  }
  random_int_list.close();
  
  
  int loop = getSize();
   
  // http://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm
  for(int i = 0; i < loop; i++) {
    bool swapped = false;
    Type temp;
    for(int j = 0; j < loop; j++) {
      /* compare the adjacent elements */   
      if(elements[j] > elements[j+1]) {
	/* swap them */
	/* std::cout << "Przed zamiana:" <<std::endl; */
	/* print(); */
	temp = elements[j];
	elements[j]=elements[j+1];
	elements[j+1]=temp;
	swapped = true;
	/* std::cout << "Po zamianie:" <<std::endl; */
	/* print(); */
      }
    }
    /*if no number was swapped that means 
      array is sorted now, break the loop.*/ 
    if(!swapped)
      break; 
  }

  print();
}



#endif
