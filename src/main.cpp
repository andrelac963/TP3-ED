//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <locale>
#include <cstring>
#include "Exceptions.hpp"
#include "HuffmanCompress.hpp"
#include "HuffmanDecompress.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");

  try
  {
    if (argc != 4)
    {
      throw InvalidArguments(argc);
    }

    const char *input = argv[1];
    const char *output = argv[2];
    const char *option = argv[3];

    if (!strcmp(option, "-c"))
    {
      HuffmanCompress *compressor = new HuffmanCompress();
      compressor->compress(input, output);
      delete compressor;
    }
    else if (!strcmp(option, "-d"))
    {
      HuffmanDecompress *decompressor = new HuffmanDecompress();
      decompressor->decompress(input, output);
      delete decompressor;
    }
    else
    {
      throw InvalidArguments(option);
    }
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}