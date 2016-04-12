// Copyright 2016 Kamil Kuczaj
#ifndef LAB06_11_04_PRJ_INC_HASHTABLE_H_
#define LAB06_11_04_PRJ_INC_HASHTABLE_H_

#include "IHashTable.h"
#include "Lista.h"

#include <string>

class HashTable : virtual public IHashTable {
 private:
  Lista<std::string> *hash_table;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Alokuje pamiec dla pola *hash_table.
   */
  HashTable();

  /*! \brief Destruktor.
   *
   * \details Zwalnia pamiec po polu *hash_table.
   */
  ~HashTable();


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
};

#endif  // LAB06_11_04_PRJ_INC_HASHTABLE_H_
