// Copyright 2016 Kamil Kuczaj
#include "Lista.h"

#include <string>
#include <iostream>

Lista::Lista() {
  head = 0;    // bad things happen if you forget about it
}

Lista::~Lista() {
  Node *conductor1 = head;  // two conductors to avoid memory
  Node *conductor2 = head;  // issues when deleting memory
  // null checking is not needed
  for (int i = 0; i < size(); i++) {
    delete conductor1;  // usuwanie pamieci
    conductor1 = conductor2->next;
    conductor2 = conductor1;
  }
}

void Lista::add(std::string item, int n) {
  if (n == 0) {  // adding at the beginning
    Node *temp = new Node;
    temp->element = item;
    temp->next = head;
    head = temp;
  } else if (n < size()) {  // inserting in the middle
    Node *inserted = new Node;
    inserted->element = item;
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation n-times
      for (int i = 0; i < n; i++)
        conductor = conductor->next;

      inserted->next = conductor->next;
      conductor->next = inserted;
    } else if (n == size()) {  // adding at the end
      Node *added_at_the_end = new Node;
      added_at_the_end->element = item;
      Node *conductor = head;
      if (conductor != 0) {
        // repeating this operation n-times
        for (int i = 0; i < n; i++)
          conductor = conductor->next;
        conductor->next = added_at_the_end;
        added_at_the_end->next = 0;  // bad things happen if you don't do this
      }
    }
  } else {
    throw("Unexpected exception while adding an element int the list"); }
}

void Lista::remove(int n) {
  if (n < size()) {
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation (n-1)-times
      for (int i = 0; i < n-1; i++)
        conductor = conductor->next;
      Node *after_cond = conductor->next;  // point to the next element
                                                // which is to be deleted
      conductor->next = after_cond->next;
      delete after_cond;
    } else {
      throw("List is empty"); }
  } else {
    throw("Index out of bounds"); }
}

bool Lista::isEmpty() {
  if (size() > 0)
    return false;
  else
    return true; }

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
  //  std::cout << "Chcemy obliczyc rozmiar listy" << std::endl;
  Node *conductor = head;
  //  std::cout << "Ustawilismy conductor na head" << std::endl;
  int temp_size = 0;
  if (conductor != 0) {
    while (conductor->next != 0) {
      std::cout << "Zawartosc listy:" << std::endl;
      print();
      conductor = conductor->next;

      temp_size++;
    }
    temp_size++;
  }

  return temp_size;
}

void Lista::print() {
  Node *conductor = head;
  if (conductor != 0) {
    while (conductor->next != 0) {
      std::cout << conductor->element << std::endl;
      conductor = conductor->next;  // jump to the next element
    }
    conductor->element;
  }
}

int Lista::search(std::string searched_word) {
  Node *conductor = head;
  int searched_index = 0;
  if (size() == 0) {
     while (conductor->next != 0) {
        if (conductor->element == searched_word)
          return searched_index;
        else
          conductor = conductor->next;

        if (searched_index < size())
          searched_index++;
        else
          return -2;  // we didn't find anything
    }
  } else {
    return -1; }  // list is empty

  return -3;
}
