//---------------------------------------------------------------------
// Arquivo      : HuffmanCompress.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef HUFFMANCOMPRESS_HPP
#define HUFFMANCOMPRESS_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Exceptions.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "Tree.hpp"
#include "Dictionary.hpp"
#include "HuffmanDecompress.hpp"

#define TAM 257

using namespace std;

class Dictionary;

class HuffmanCompress
{
private:
  unsigned int frequency[TAM] = {0};

public:
  HuffmanCompress();
  ~HuffmanCompress();
  void countFrequency(const char *input);
  string encode(Dictionary *dictionary, const char *input);
  void saveCompressedFile(const char *output, string code);
  void saveIndex(const char *output);
  void compress(const char *input, const char *output);
};

#endif