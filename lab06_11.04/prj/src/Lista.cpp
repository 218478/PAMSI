// Copyright 2016 Kamil Kuczaj
#include "Lista.h"

#include <string>
#include <iostream>

Lista::Lista() {
  head = 0;    // bad things happen if you forget about it
  size_of_list = 0;  // for debug
}

Lista::~Lista() {
  Node *conductor1 = head;  // two conductors to avoid memory
  Node *conductor2 = head;  // issues when deleting memory
  // null checking is not needed
  while (conductor1 != 0) {
    delete conductor1;  // usuwanie pamieci
    conductor1 = conductor2->next;
    conductor2 = conductor1;
  }
}

// dziala wstawianie na poczatku, gdy lista pusta lub gdy nie jest pusta
// dziala wstawianie w srodku, oraz na koncu
// dziala wyjatek informujacy o indeksie
void Lista::add(std::string item, int n) {
  int current_size = size();
  if (n > current_size)  // if we want to add an element beyond list
    throw("Requested index out of bounds");

  if (isEmpty()) {  // if the list is empty
    Node* temp = new Node;
    temp->element = item;
    // // for debug
    // std::cout << "Dodajemy na poczatku i lista pusta." << std::endl;
    head = temp;
    head->next = 0;
    size_of_list++;

  } else {  // and when it's not empty
    Node* temp = new Node;
    temp->element = item;

    if (n == 0) {  // when we adding at the beginning
      // // for debug
      // std::cout << "Dodajemy na poczatku." << std::endl;
      temp->next = head;
      head = temp;
      size_of_list++;
    } else {
      Node *conductor = head;

      if (n < current_size) {  // when inserting
        // // for debug
        // std::cout << "Wsadzamy do srodka." << std::endl;
        for (int i = 0; i < (n-1); i++)
          conductor = conductor->next;

        temp->next = conductor->next;
        conductor->next = temp;
        size_of_list++;
      }

      if (n == current_size) {  // when adding at the end
        // // for debug
        // std::cout << "Dolaczamy na koniec." << std::endl;
        for (int i = 0; i < (n-1); i++)
          conductor = conductor->next;

        temp->next = 0;
        conductor->next = temp;
      }
    }
  }
}


// dziala usuwanie z poczatku, ze srodka i z konca
// dziala rowaniez wyswietlanie wyjatkow w przypadku gdy lista pusta
// lub odwolujemy sie do zbyt duzego indeksu
std::string Lista::remove(int n) {
  std::string word;

  if (size() == 0)
    throw("List is empty");
  if (n < size()) {
    Node *conductor = head;

    if (n == 0) {  // if we want to remove at the beginning
      head = conductor->next;
      word = conductor->element;
      delete conductor;
    } else {
      // repeating this operation (n-1)-times
      for (int i = 0; i < n-1; i++)
        conductor = conductor->next;
      Node *after_cond = conductor->next;  // point to the next element
      // which is to be deleted
      conductor->next = after_cond->next;
      word = after_cond->element;
      delete after_cond; }
    }
  else
    throw("Index out of bounds");

  return word;
}

// dziala
bool Lista::isEmpty() {
  if (size() > 0)
    return false;
  else
    return true; }

// dziala
std::string Lista::get(int n) {
  std::string temp;
  if (n < size()) {
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation n-times
      for (int i = 0; i < n; i++)
        conductor = conductor->next;
      temp = conductor->element;
    } else {
      throw("List is empty"); }
  } else {
    throw("Index out of bounds"); }

  return temp;
}

int Lista::size() {
  Node *conductor = head;
  int temp_size = 0;
  while (conductor != 0) {
    conductor = conductor->next;
    temp_size++;
  }

  return temp_size;

  // for debug
  //  return size_of_list;
}

void Lista::print() {
  Node *conductor = head;
  while (conductor != 0) {
    std::cout << conductor->element << std::endl;
    conductor = conductor->next;  // jump to the next element
  }
}


// dziala funkcja search
int Lista::search(std::string searched_word) {
  Node *conductor = head;
  int searched_index = 0;

  if (isEmpty())
    return -1;  // list is empty

  while (conductor != 0) {
    if (conductor->element == searched_word)
      return searched_index;

    searched_index++;
    conductor = conductor->next;
  }
  return -2;   // we didn't find anything
}

