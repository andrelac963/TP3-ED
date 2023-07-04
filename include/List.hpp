//---------------------------------------------------------------------
// Arquivo      : List.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cstdlib>
#include "Node.hpp"
#include "Tree.hpp"

#define TAM 257

using namespace std;

class Node;

class List
{
private:
  Node *head;
  int size;

public:
  List();
  ~List();
  void insert(Node *node);
  void fillList(unsigned int frequency[]);
  Node *removeHead();
  Node *getHead();
  Node *getNode(int index);
  int getSize();
  void printList();
};

#endif