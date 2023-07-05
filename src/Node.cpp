//---------------------------------------------------------------------
// Arquivo      : Node.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#include "Node.hpp"

// Construtor padrão
Node::Node()
{
  this->character = '\0';
  this->frequency = 0;
  this->left = NULL;
  this->right = NULL;
  this->next = NULL;
}

// Construtor que recebe o caractere e a frequência
Node::Node(unsigned char character, unsigned int frequency)
{
  this->character = character;
  this->frequency = frequency;
  this->left = NULL;
  this->right = NULL;
  this->next = NULL;
}

// Destrutor
Node::~Node()
{
  delete this->left;
  delete this->right;
}