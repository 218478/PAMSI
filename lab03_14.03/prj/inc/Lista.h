// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_H_
#define LAB03_14_03_PRJ_INC_LISTA_H_

#include "IRunnable.h"
#include "ILista.h"

#include <cstddef>   // to use the NULL macro
#include <string>    // to deal with words saving and searching
#include <iostream>  // to print the contents of the list
#include <fstream>   // to deal with loading words from the dictionary

/*! \file Lista.h
 *
 * \brief Implementacja jednokierunkowej listy.
 *
 * \details Ze wzledu na komplikacje implementacji mechanizmow przy uzyciu
 *          szablonow, zdecydowalem sie je usunac z konstrukcji programu.
 *
 * \author Kamil Kuczaj.
 */

/*! \brief Klasa Lista, ktora symuluje zachowanie klasy list z biblioteki STL.
 *
 * \details Zajmuje sie dynamiczna alokacja pamieci. Lista jest jednokierunkowa.
 *          Mamy dostep do pierwszego elementu w liscie
 */
class Lista: ILista {
  /*! \brief Pierwszy element listy.
   *
   * \details Wskazuje na pierwszy element listy.
   */
  Node *head;

  /*! \brief Przechowuje rozmiar listy.
   *
   * \details Dzieki zastosowaniu tej zmiennej, o wiele latwiej debugowac Lista.
   *          Pozwala to na kontrole mechanizmow sprawdzania. Powinien byc
   *          zawsze dodatni.
   */
  int size_of_list;

 public:
  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy. Alokuje dla niego pamiec.
   */
  Lista();

  /*! \brief Destruktor.
   *
   * \details Usuwa cala pamiec listy "skaczac" po jej elementach.
   */
  ~Lista();

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany. Slowo typu string.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(std::string item, int index);

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \retval true Udalo sie usunac element o podanym indeksie.
   * \retval false Nie udalo sie usunac elementu o podanym indeksie.
   */
  virtual bool remove(int index);

  /*! \brief Sprawdza czy lista jest pusta.
   *
   * \details Sprawdza czy w liscie sa jakies elementy.
   *
   * \retval true Lista jest pusta.
   * \retval false Lista nie jest pusta.
   */
  virtual bool isEmpty();

  /*! \brief Zwraca element z dowolnego miejsca listy.
   *
   * \details Zwraca element z miejsca wskazywanego przez zmienna index.
   *          Wyjatki sa typu: const char *
   *          "Empty list"          - pusta lista
   *          "Index out of bounds" - przekroczono zakres, nie ma tylu elementow
   *
   * \return Zwraca element typu std::string.
   */
  virtual std::string get(int index);

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size();

  /*! \brief Szuka elementu.
   *
   * \details Szuka elementu wskazanego przez uzytkownika. W funkcji nastepuje
   *          Segmentation fault, gdy probujemy znalezc element, ktorego tam
   *          nie ma. W ogole sposob kodowania bledow gdy na nie napotka jest
   *          debilny ale nie mialem wystarczajaco duzo czasu aby to przerobic.
   *
   * \param[in] desired_element Poszukiwana fraza.
   *
   * \retval index>0         Znalazl element i wyswietlil.
   * \retval 1199999999      Nie znalazl i nie wyswietlil elementu. Wybrana
   *                         wartosc, poniewaz nigdy tak duzej liczby elementow
   *                         nie wczytamy. 10 cyfr.
   * \retval 1198989898      Lista pusta. Wybrana wartosc, poniewaz nigdy tak
   *                         duzej liczby elementow nie wczytamy. 10 cyfr.
   */
  virtual int run(std::string desired_element);

  /*! \brief Zapisuje liste slowami.
   *
   * \details Zapisuje liste slowami zaczerpnietymi ze slownika. !!! WAZNE !!!!
   *          Funkcja powinna byc uzyta tylko na poczatku, gdy cala lista jest
   *          pusta. Inaczej nastapi nadpisanie elementow poczatkowych.
   *
   * \param[in] desired_size Ile elementow ma zostac wczytanych.
   */
  virtual void prepare(int desired_size);


  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print();
};

// Lista::Lista() {
//   head = 0;
//   size_of_list = 0; }

// Lista::~Lista() { 
//   Node<Type> *conductor = head;
//   while(conductor != 0) {
//     conductor=conductor->next;
//     delete conductor;
//   }
// }

// template <class Type> uint Lista<Type>::size() { 
//   Node<Type> *conductor;
//   uint size_temp=0;

//   conductor = head;
//   if ( conductor != 0 ) {
//     while ( conductor->next != 0) {
//       conductor = conductor->next;
//       size_temp++;
//     }
//     size_temp++; // it wasn't counting the last element, since this->next was
//                 // pointing to NULL
//   }

//   return size_temp;
// }

// // old method and not optimized
// // 
// // template <class Type> bool Lista<Type>::isEmpty() { 
// //   return (size() == 0) ? true : false; 
// // } 

// template <class Type> void Lista<Type>::add(Type item, uint index) {
//   uint size_temp = size();

//   // if we want to add it at the beginning
//   if (index == 0)
//     {
//       Node<Type> *temp = new Node<Type>;
//       temp->element=item;
//       temp->next = head;
//       head=temp;
//     }
//   else if(size_temp > index)
//     {
//       Node<Type> *temp = new Node<Type>;
//       temp->element=item;
//       Node<Type> *conductor = head;
      
//       // just at the element before indexed one
//       for(uint i=0; i < index-1; i++) {
// 	conductor=conductor->next;
//       }

//       temp->next=conductor->next;
//       conductor->next=temp;
//     }
//   else if(size_temp == index) // if we want to add at the end
//     {
//       Node<Type> *temp = new Node<Type>;
//       temp->element=item;
//       Node<Type> *conductor = head;
      
//       // just at the element before indexed one
//       for(uint i=0; i < index-1; i++) {
// 	conductor=conductor->next;
//       }
      
//       conductor->next = temp;
//       temp->next = 0;
//     }
//   else
//     {
//       std::cerr << "Can't add '" << item << "': index out of bounds" << std::endl;
//     }
  
//   // Trying to implement a solution using methods failed, multiple times.
//   // That's why I have decided to resign.
//   //  temp->setElem(item);
//   //  head->setNext(temp->getNext());
// }

// template <class Type> void Lista<Type>::print() {
//   Node<Type> *conductor;
//   conductor = head;

//   while(conductor != 0) {
//     std::cout << conductor->element << std::endl;
//     conductor=conductor->next;
//   }
// }

// template <class Type> bool Lista<Type>::remove(uint index) { 
//   uint size_temp = size();
//   Node<Type> *after_conductor = 0;
//   Node<Type> *conductor = head;

//   // if we want to add it at the beginning
//   if (index == 0 && !isEmpty())
//     {
//       head = conductor->next;
//       delete conductor; // delete the beginning
//       return true; // return success
//     }
//   else if(size_temp > index)
//     {
   
//       // just at the element before indexed one
//       for(uint i=0; i < index-1; i++) {
// 	conductor=conductor->next;
//       }
//       after_conductor = conductor->next;
//       conductor->next=conductor->next->next; // connect the previous with the next
//                                             // after the indexed one
//       delete after_conductor;
//       return true; // return success
//     }
//   else if(size_temp == index) // if we want to add at the end
//     {
//       // just at the element before indexed one
//       for(uint i=0; i < index-1; i++) {
// 	conductor=conductor->next;
//       }
      
//       after_conductor = conductor->next;
//       conductor->next = 0;
//       delete after_conductor;
//       return true; // return success
//     }
//   else
//     {
//       std::cerr << "Can't remove element no '" << index
// 		<< "': index out of bounds" << std::endl;
//       return false; // return failure
//     }

//   //  return true;
// }

// template <class Type> Type Lista<Type>::get(uint index) {
//   Node<Type> *conductor = head;
//   uint current_index=0;

//   if ( isEmpty() )
//     throw("Empty list");

//   if (index > size()-1)
//     throw("Index out of bounds");

//   while(conductor->next != 0 && current_index != index) {
//     conductor=conductor->next;
//     current_index++;
//   }

//   return conductor->element;
// }

// template <class Type> bool Lista<Type>::isEmpty() {
//   return (head == 0) ? true : false;
// }

// template <class Type> uint Lista<Type>::run(Type desired_element) {
//   Node<Type> *conductor;
//   uint searched_index=0;

//   conductor = head;
//   if(isEmpty())
//     throw("Empty list");

//   if ( conductor->element != desired_element) {
//     while ( conductor->next != 0 && conductor->next->element != desired_element) {
//       conductor = conductor->next;
//       searched_index++;
//     }
//     searched_index++; // it wasn't counting the last element, since
//                       // conductor->next was pointing to NULL
//   }

//   /* // for debug */
//   /* std::cout << "Element no: " << searched_index << " is: " */
//   /* 	    << conductor->next->element << std::endl; */

//   /* std::cout << "conductor->next = " << conductor->next << std::endl; */
//   /* std::cout << "searched_index = " << searched_index << std::endl; */
  
//   if(conductor->next->element == desired_element && searched_index != size()-1)
//     return searched_index; // it is an element inside the list, not at the end
//   else if (searched_index == size() - 1)
//     return searched_index; // at the end and found the word
//   else
//     return 1199999999; // we are at the end of list and haven't found anything
    
// }

// template <class Type> void Lista<Type>::prepare(uint desired_size) {
//   std::ifstream dictionary;
//   dictionary.open("109582_English_Words.txt",std::fstream::in);
//   try {
//     dictionary.exceptions(dictionary.failbit);
//   }
//   catch(const std::ios_base::failure & ex) {
//     std::cerr << "Error! Couldn't find or open a file" << ex.what() << std::endl;
//   }

//   // read input only if the list is empty and file stream is open
//   if(dictionary.is_open() && isEmpty() ) {
//     // http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
//     // user Wilhelmtell '08
//     Type word;
//     for(uint i=0; i < desired_size; i++) {
//       dictionary >> word;
//       if(dictionary.eof()) break;
//       add(word,i);
//     }
//   }
//   dictionary.close();
// }


#endif  // LAB03_14_03_PRJ_INC_LISTA_H_
