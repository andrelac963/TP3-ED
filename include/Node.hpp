//---------------------------------------------------------------------
// Arquivo      : Node.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef NODE_HPP
#define NODE_HPP

#include <cstdlib>

class Node
{
public:
  unsigned char character;
  unsigned int frequency;
  Node *left, *right, *next;

  Node();
  Node(unsigned char character, unsigned int frequency);
  ~Node();
};

#endif