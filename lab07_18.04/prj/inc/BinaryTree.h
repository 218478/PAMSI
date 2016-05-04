// Copyright 2016 Kamil Kuczaj
#ifndef LAB07_18_04_PRJ_INC_BINARYTREE_H_
#define LAB07_18_04_PRJ_INC_BINARYTREE_H_

#include "IBinaryTree.h"

#include <vector>
#include <iostream>

/*! \brief Implementacja drzewa binarnego.
 *
 * \details Drzewo to ma jak najwierniej przypominac drzewo czerwono-czarne.
 *              Nie zaimplementowano metod usuwających elementy z drzewa, gdyz
 *              nie bylo to istotne dla, zadanego przez prowadzacego, cwiczenia.
 *              Zgodnie z ogolnie przyjetymi zasadami po lewej stronie zawsze
 *              znajduja sie elementy mniejsze od rodzica, a po prawej wieksze.
 *              Czesc kodu zostala skopiowana ze strony Wikipedii.
 */
template <class Type>
 class BinaryTree : IBinaryTree<Type> {
 private:
  /*! \brief Enum dla zakodowania kolorow.
   *
   * \details BLACK to inaczej 0, a RED to po prostu 1.
   */
   enum { BLACK, RED }; 

  /*! \ brief Struktura wezlow.
   *
   * \details Struktura wezla, o ktory bedzie opieralo sie drzewo. Mamy dostep
   *              do rodzica elementu oraz lewego i prawego dziecka.
   */
   struct Node {
    Type element;
    int color;
    Node *parent, *left, *right;
    Node(Type i) : element(i), parent(nullptr), left(nullptr), right(nullptr) {}
  };

  /*! \brief Zwraca dziadka elementu.
   *
   * \details Funkcja zwraca rodzica rodzica konkretnego wezla.
   */
   Node* grandparent(Node *n) {
    if ((n != nullptr) && (n->parent != nullptr))
      return n->parent->parent;
    else
      return nullptr;
  }

  /*! \brief Zwraca wujka elementu.
    *
    * \details Zwraca drugie dziecko dziadka, ktore nie jest rodzicem
    *              wezla.
    */
    Node* uncle(Node *n) {
      Node *g = grandparent(n);
      if (g == nullptr)
        return nullptr; // No grandparent means no uncle
      if (n->parent == g->left)
        return g->right;
      else
        return g->left;
    }

    void rotate_right(Node *n) {
      Node* pivot = n->left;
      n->left = pivot->right;
      pivot->right = n;
      n = pivot;
    }


    void rotate_left(Node *n) {
      Node* pivot = n->right;
      n->right = pivot->left;
      pivot->left = n;
      n = pivot;
    }

    void insert_case1(Node *n) {
      std::cout << grandparent(n) << std::endl;
      if (n->parent == nullptr)
        n->color = BLACK;
      else
        insert_case2(n);
    }

    void insert_case2(Node *n) {
     if (n->parent->color == BLACK)
  return; /* Tree is still valid */
       else
        insert_case3(n);
    }

    void insert_case3(Node *n) {
      Node *u = uncle(n), *g;

      if ((u != nullptr) && (u->color == RED)) {
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
      } else {
        insert_case4(n);
      }
    }

    void insert_case4(Node *n) {
      Node *g = grandparent(n);

      if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);

 /*
 * rotate_left can be the below because of already having *g =  grandparent(n) 
 *
 * struct Node *saved_p=g->left, *saved_left_n=n->left;
 * g->left=n; 
 * n->left=saved_p;
 * saved_p->right=saved_left_n;
 * 
 * and modify the parent's Nodes properly
 */

 n = n->left;

} else if ((n == n->parent->left) && (n->parent == g->right)) {
  rotate_right(n->parent);

 /*
 * rotate_right can be the below to take advantage of already having *g =  grandparent(n) 
 *
 * struct Node *saved_p=g->right, *saved_right_n=n->right;
 * g->right=n; 
 * n->right=saved_p;
 * saved_p->left=saved_right_n;
 * 
 */

 n = n->right; 
}
insert_case5(n);
}

void insert_case5(Node *n) {
  Node *g = grandparent(n);

  n->parent->color = BLACK;
  g->color = RED;
  if (n == n->parent->left)
    rotate_right(g);
  else
    rotate_left(g);
}


  /*! \brief Tablica dynamiczna, na ktorej zbudowane jest drzewo.
   *
   * \details Wykorzystuje pojemnik typu std::vector do przechowywania
   *              wezlow.
   */
   std::vector<Node> tree;

  /*! \brief Korzen drzewa.
   *
   * \details Przechowuje adres do korzenia drzewa.
   */
   Node* head;

 public:
  /*! \brief Bezparametryczny konstuktor
   *
   * \details Inicjalizuje korzen jako nullptr.
   */
   BinaryTree() : head(nullptr) {}

  /*! \brief Dodaje element do drzewa.
   *
   * \details Dodaje element do drzewa wstawiajac go w odpowiednie
   *          miejsce.
   */
   virtual void put(Type elem) {
    tree.push_back(Node(elem));
    if (tree.size() == 1) {
      head = &tree[0];
    }
    else {
      Node *temp = head;
      while (true) {
        if (elem < temp->element) {
          if (temp->left == nullptr) {
            temp->left = &tree.back();
            break;
          }
          else
            temp = temp->left;
        }
        else
        {
          if (temp->right == nullptr) {
            temp->right = &tree.back();
            break;
          }
          else
            temp = temp->right;
        }
      }
    }
    //insert_case1(&tree.back());
  }

  /*! \brief Wyszukuje element w drzewie.
   *
   * \details Wyszukuje element typu Type w drzewie.
   *          Zwraca prawde gdy znajdzie, falsz gdy nie.
   *
   * \param[in] element Szukany element.
   *
   * \retval true Element znajduje sie w drzewie.
   * \retval false Elementu nie ma w drzewie.
   */
   virtual bool search(Type elem) const {
    Node *temp = head;

    while (true) {
      if (elem == temp->element)
        return true;

      if (elem < temp->element) {
        if (temp->left == nullptr)
          break;
        else
          temp = temp->left;
      }
      else
      {
        if (temp->right == nullptr)
          break;
        else
          temp = temp->right;
      }
    }

    return false;
  }

  /*! \brief Wyswietla zawartosc drzewa.
   *
   * \details Wydrukowuje na standardowym wyjsciu zawartosc drzewa.
   *          Kazdy poziom jest drukowany w osobnej linii.
   */
   virtual void print() {
    Node *temp = head;
    std::cout << "    " << temp->element << std::endl;
    if (temp->left != nullptr)
      std::cout << temp->left->element << "\t";
    if (temp->right != nullptr)
      std::cout << temp->right->element << "\t";

    std::cout << std::endl << "Zawartosc:" << std::endl;
    for (Node i : tree)
      std::cout << i.element << std::endl;
  }
};


#endif  // LAB07_18_04_PRJ_INC_BINARYTREE_H_
