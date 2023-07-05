//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <locale>
#include <sys/resource.h>
#include <cstring>
#include "Exceptions.hpp"
#include "HuffmanCompress.hpp"
#include "HuffmanDecompress.hpp"

using namespace std;

// Função para calcular o tempo de execução
float difTempoUsuario(struct rusage *start, struct rusage *end)
{
  return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
         1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");

  struct rusage start, end;

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
      getrusage(RUSAGE_SELF, &start);

      cout << endl
           << "Comprimindo arquivo..." << endl;

      // Compressão do arquivo de entrada e gravação do arquivo de saída
      HuffmanCompress *compressor = new HuffmanCompress();
      compressor->compress(input, output);
      delete compressor;

      getrusage(RUSAGE_SELF, &end);
      cout << "Tempo de execução: " << difTempoUsuario(&start, &end) << " segundos" << endl;
    }
    else if (!strcmp(option, "-d"))
    {
      getrusage(RUSAGE_SELF, &start);

      cout << endl
           << "Descomprimindo arquivo..." << endl;

      // Descompressão do arquivo de entrada e gravação do arquivo de saída
      HuffmanDecompress *decompressor = new HuffmanDecompress();
      decompressor->decompress(input, output);
      delete decompressor;

      getrusage(RUSAGE_SELF, &end);
      cout << "Tempo de execução: " << difTempoUsuario(&start, &end) << " segundos" << endl;
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