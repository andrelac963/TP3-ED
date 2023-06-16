//---------------------------------------------------------------------
// Arquivo      : huffmanCompress.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef HUFFMANCOMPRESS_HPP
#define HUFFMANCOMPRESS_HPP

using namespace std;

class HuffmanCompress
{
public:
  HuffmanCompress();
  ~HuffmanCompress();
  void compress(const char *input, const char *output);
};

#endif