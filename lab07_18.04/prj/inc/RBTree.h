// Drzewo czerwono-czarne
// Data: 11.06.2013
// (C)2013 mgr Jerzy Wałaszek
//------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*! \brief Typ węzłów drzewa RBT.
 */
struct RBTNode
{
  RBTNode * up;
  RBTNode * left;
  RBTNode * right;
  int key;
  char color;
};

/*! \brief Definicja typu obiektowego TRBTree.
 */
class TRBTree
{
  private:
    RBTNode S;             // Węzeł strażnika
    RBTNode * root;        // Korzeń drzewa czerwono-czarnego
    string cr,cl,cp;       // Łańcuchy do znaków ramek

    void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

  public:
    TRBTree();             // Konstruktor klasy
    ~TRBTree();            // Destruktor klasy
    void DFSRelease(RBTNode * p); // Usuwa rekurencyjnie drzewo
    void print();          // Wypisuje drzewo
    RBTNode * findRBT(int k); // Wyszukuje węzeł o kluczu k
    RBTNode * minRBT(RBTNode * p); // Wyszukuje najmniejszy węzeł w p
    RBTNode * succRBT(RBTNode * p);// Wyszukuje następnik p
    void rot_L(RBTNode * A); // Rotacja w lewo względem A
    void rot_R(RBTNode * A); // Rotacja w prawo względem A
    void insertRBT(int k);   // Wstawia węzeł o kluczu k
    void removeRBT(RBTNode * X); // Usuwa węzeł X
};


// int main()
// {
//   int Tk[MAXN];          // Tablica kluczy węzłów
//   int i,x,i1,i2;
//   TRBTree * RBT;         // Obiekt drzewa czerwono-czarnego

//   srand(time(NULL));     // Inicjujemy generator pseudolosowy

//   RBT = new TRBTree;     // Tworzymy puste drzewo

//   for(i = 0; i < MAXN; i++) // Tablicę wypełniamy wartościami kluczy
//     Tk[i] = i + 1;

//   for(i = 0; i < 300; i++)  // Mieszamy tablicę
//   {
//     i1 = rand() % MAXN;     // Losujemy 2 indeksy
//     i2 = rand() % MAXN;

//     x = Tk[i1];             // Wymieniamy Tk[i1] <-->. Tk[i2]
//     Tk[i1] = Tk[i2];
//     Tk[i2] = x;
//   }

//   for(i = 0; i < MAXN; i++) // Na podstawie tablicy tworzymy drzewo czerwono-czarne
//   {
//     cout << Tk[i] << " ";
//     RBT->insertRBT(Tk[i]);
//   }

//   cout << endl << endl;

//   RBT->print();             // Wyświetlamy zawartość drzewa

//   cout << endl << endl;

//   for(i = 0; i < 300; i++)  // Ponownie mieszamy tablicę
//   {
//     i1 = rand() % MAXN; i2 = rand() % MAXN;
//     x = Tk[i1]; Tk[i1] = Tk[i2]; Tk[i2] = x;
//   }

//   for(i = 0; i < MAXN >> 1; i++) // Usuwamy połowę węzłów
//   {
//     cout << Tk[i] << " ";
//     RBT->removeRBT(RBT->findRBT(Tk[i]));
//   }

//   cout << endl << endl;

//   RBT->print();            // Wyświetlamy zawartość drzewa

//   delete RBT;              // Usuwamy drzewo z pamięci

//   return 0;
// } 