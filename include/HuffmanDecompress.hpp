//---------------------------------------------------------------------
// Arquivo      : HuffmanDecompress.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef HUFFMANDECOMPRESS_HPP
#define HUFFMANDECOMPRESS_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Exceptions.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "Tree.hpp"
#include "Dictionary.hpp"

using namespace std;

#define TAM 257

class Dictionary;

class HuffmanDecompress
{
private:
  unsigned int frequency[TAM] = {0};

public:
  HuffmanDecompress();
  ~HuffmanDecompress();
  void readIndex(const char *input);
  void decode(const char *input, const char *output, Node *root);
  void decompress(const char *input, const char *output);
};

#endif