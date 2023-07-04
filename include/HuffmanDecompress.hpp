//---------------------------------------------------------------------
// Arquivo      : HuffmanDecompress.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
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

class HuffmanDecompress
{
public:
  HuffmanDecompress();
  ~HuffmanDecompress();
  void Decompress(const char *input, const char *output);
};

#endif