//---------------------------------------------------------------------
// Arquivo      : Dictionary.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
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

class Dictionary
{
public:
  char **dictionary;
  Dictionary(int rows);
  ~Dictionary();
  void fillDictionary(Node *root, char *code, int rows);
  int sizeText(unsigned char *text);
  char *getCode(unsigned char character);
  void printDictionary();
};

#endif