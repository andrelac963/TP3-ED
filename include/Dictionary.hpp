//---------------------------------------------------------------------
// Arquivo      : Dictionary.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "Exceptions.hpp"
#include "Node.hpp"

#define TAM 257

using namespace std;

class Node;

class Dictionary
{
public:
  char **dictionary;
  Dictionary(int rows);
  ~Dictionary();
  void fillDictionary(Node *root, char *code, int rows);
  char *getCode(unsigned char character);
  void setCode(unsigned char character, string code);
  void printDictionary();
};

#endif