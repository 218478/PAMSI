// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_TEST_H_
#define LAB03_14_03_PRJ_INC_LISTA_TEST_H_

#include "Lista.h"
#include "IRunnable.h"

#include <cstdlib>   // to generate random numbers
#include <iostream>  // to display messages in the console
#include <string>    // to deal with string words

class Lista_test: IRunnable {
 private:
  Lista list;

 public:
/*! \brief Szuka elementu.
   *
   * \details Szuka elementu wskazanego przez uzytkownika. W funkcji nastepuje
   *          Segmentation fault, gdy probujemy znalezc element, ktorego tam
   *          nie ma. W ogole sposob kodowania bledow gdy na nie napotka jest
   *          debilny ale nie mialem wystarczajaco duzo czasu aby to przerobic.
   *
   * \param[in] desired_element Poszukiwana fraza.
   *
   * \retval >0         Znalazl element i wyswietlil.
   * \retval -1         Nie znalazl i nie wyswietlil elementu.
   * \retval -2         Lista pusta.
   */
  virtual void run() {
    std::string random_word = getRandomWordFromTheDict();
    int result = list.search(random_word);
    if (result < 0)
      std::cerr << "! ERROR: code " << result << std::endl;
    else
      std::cout << "Found: " << random_word << " at index: "
                << result << std::endl;
  }

  /*! \brief Zapisuje liste slowami.
   *
   * \details Zapisuje liste slowami zaczerpnietymi ze slownika. !!! WAZNE !!!!
   *          Funkcja powinna byc uzyta tylko na poczatku, gdy cala lista jest
   *          pusta. Inaczej nastapi nadpisanie elementow poczatkowych.
   *
   * \param[in] desired_size Ile elementow ma zostac wczytanych.
   */
  virtual void prepare(int desired_size) {
    std::fstream dictionary;
    dictionary.open("109582_English_Words.txt", std::fstream::in);
    try {
      dictionary.exceptions(dictionary.failbit);
    }
    catch(const std::ios_base::failure & ex) {
      std::cerr << "Error! Couldn't find or open a file"
                << ex.what() << std::endl;
    }

    // read input only if the list is empty and file stream is open
    if (dictionary.is_open() && list.isEmpty()) {
      // http://stackoverflow.com
      // /questions/21647/reading-from-text-file-until-eof-repeats-last-line
      // user Wilhelmtell '08
      std::string word;
      for (int i = 0; i < desired_size; i++) {
        dictionary >> word;
        if (dictionary.eof()) break;
        try {
          list.add(word, i); }
        catch (const char* message) {
          std::cout << message << std::endl; }
      }
    }
    /* // for debug */
    /* list.print(); */
    /* for (int i = 0 ; i < 10; i++) */
    /*   std::cout << "Element o indeksie nr " << i << " to : " */
    /*             << list.get(i) << std:: endl; */
    dictionary.close();
  }

  std::string getRandomWordFromTheDict() {
    std::fstream dictionary;
    std::string word;

    dictionary.open("109582_English_Words.txt", std::fstream::in);

    try {
      dictionary.exceptions(dictionary.failbit);
    }
    catch(const std::ios_base::failure & ex) {
      std::cerr << "Error! Couldn't find or open a file" << ex.what()
                << std::endl;
    }

    // generating random number in 0 to 109582-1
    srand(time(NULL));
    int random_number = rand()%(109582-1);

    // stackoverflow.com
    // /questions/21647/reading-from-text-file-until-eof-repeats-last-line
    // user Wilhelmtell '08
    if (dictionary.is_open()) {
      for (int i=0; i < random_number; i++) {
        dictionary >> word;
        if (dictionary.eof()) break;
      }
    }

    dictionary.close();
    return word;
  }
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_TEST_H_
