//---------------------------------------------------------------------
// Arquivo      : Node.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "Node.hpp"

Node::Node()
{
  this->character = '\0';
  this->frequency = 0;
  this->left = NULL;
  this->right = NULL;
  this->next = NULL;
}

Node::Node(unsigned char character, unsigned int frequency)
{
  this->character = character;
  this->frequency = frequency;
  this->left = NULL;
  this->right = NULL;
  this->next = NULL;
}

Node::~Node()
{
  delete this->left;
  delete this->right;
}