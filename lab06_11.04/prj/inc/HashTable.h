// Copyright 2016 Kamil Kuczaj
#ifndef LAB06_11_04_PRJ_INC_HASHTABLE_H_
#define LAB06_11_04_PRJ_INC_HASHTABLE_H_

#include "IHashTable.h"
#include "Tablica.h"
// #include "Lista.h" bo nie umiem jej zaimplementowac na tablicy

#include <string>
#include <list>


/*! \brief Klasa tablicy asocjacyjnej.
 *
 * \details Zaimplementowana na bazie tablicy hashujacej.
 *          !!! WAZNE !!!
 *          Konstruujac te tablice, podac jako parametr wielekrotnosc 100
 *          setki. Jest to wielkosc bucketow i dzielenie musi zwracac liczbe
 *          calkowita.
 */
class HashTable : virtual public IHashTable {
 private:
  struct my_element {
    std::string key;
    int number;
  };

  // needed to search through STL list
  struct find_key {
    std::string key;
    find_key(std::string key): key(key) {}
    bool operator() ( const my_element& m ) const {
      return m.key == key;  }
  };

  std::list<my_element> *hash_table;
  int hash_table_size;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Alokuje pamiec dla pola *hash_table. Tworze tablice, w ktorej
   *          moze znajdowac sie nieskonczona ilosc bucketow, kazdy bucket po
   *          100 elementow. Tutaj dzielenie int przez inta zawsze spowoduje
   *          calkowity wynik.
   */
  explicit HashTable(int no_of_elements);

  /*! \brief Destruktor.
   *
   * \details Zwalnia pamiec po polu *hash_table.
   */
  ~HashTable();

  /*! \brief Algorytm haszujacy.
   *
   * \details Czyli tzw funkcja sortujaca. Algortym na podstawie postu
   *          uzytkownika cnicutar ze strony:
   *          stackoverflow.com/questions/7666509/hash-function-for-string
   *          www.cse.yorku.ca/~oz/hash.html
   *
   *          Nazwa tego algorytmu to djb2.
   *
   * \param[in] key Wartosc, na podstawie ktorej ma zostac zwrocony int.
   */
  int hashFunction(const std::string& key) const;

  /*! \brief Getter do tablicy.
   *
   * \details Po podaniu klucza, w tym przypadku nazwiska, funkcja zwroci
   *          nam numer telefonu, ktory jest przypisany do nazwiska. Zupelnie
   *          jak w rzeczywistej ksiazce telefonicznej. W funkcji obowiazuja
   *          dwa wyjatki:
   *          - EmptyList    ==> rzucany w przypadku gdy nie ma zadnego rekordu,
   *                             tj. lista (tom) jest pusta
   *          - KeyIsNotThere ==> rzucany w przypadku gdy nie znalezlismy podanego
   *                             klucza, a lista (tom) nie jest pusta.
   *
   * \param[in] key Klucz, po ktorym wyszukiwana jest odpowiednia lista.
   */
  virtual int operator[] (std::string key) const;

  /*! \brief Setter do tablicy.
   * \details Dodaje element do tomu, pod warunkiem, ze nie ma takiego elementu.
   *          W przypadku gdy znajdzie juz taki rzuca wyjatek:
   *          - DuplicateElement ==> rzucany w przypadku, gdy podany klucz jest
   *                                 juz w bazie.
   *
   * \param[in] key     Klucz, po ktorym wyszukiwana jest odpowiednia lista. Musi
   *                    byc inny niz te, ktore znajduja sie juz w tabliicy.
   * \param[in] value   Numer telefonu przypisany do nazwiska. To ten element
   *                    bedzie zwracany przy wyszukiwaniu.
   */
  virtual void put(std::string key, int value);

  void print();
};

#endif  // LAB06_11_04_PRJ_INC_HASHTABLE_H_
