//---------------------------------------------------------------------
// Arquivo      : HuffmandECompress.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef HUFFMANDECOMPRESS_HPP
#define HUFFMANDECOMPRESS_HPP

using namespace std;

class HuffmanDecompress
{
public:
  HuffmanDecompress();
  ~HuffmanDecompress();
  void decompress(const char *input, const char *output);
};

#endif