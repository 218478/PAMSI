// Copyright 2016 Kamil Kuczaj
#ifndef LAB06_11_04_PRJ_INC_IHASHTABLE_H_
#define LAB06_11_04_PRJ_INC_IHASHTABLE_H_

#include <string>

/*! \brief Interfejs tablicy z hashowaniem
 *
 * \details Interfejs tablicy z hashowaniem, ktory opisuje jakie
 *          funkcje beda znajdywaly sie w implementacji oraz co beda zwracac.
 */
class IHashTable {
 public:
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
virtual int operator[] (std::string key) const = 0;

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
virtual void put(std::string key, int value) = 0;
};

#endif  // LAB06_11_04_PRJ_INC_IHASHTABLE_H_
