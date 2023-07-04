//---------------------------------------------------------------------
// Arquivo      : Tree.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <cstdlib>
#include "Node.hpp"
#include "List.hpp"

using namespace std;

class List;

class Tree
{
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void buildTree(List *list);
  void setRoot(Node *root);
  Node *getRoot();
  int getHeight(Node *root);
  void printTree(Node *root, int height);
};

#endif