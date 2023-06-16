//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <exception>

class InvalidArgumentsException : public std::exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid arguments";
  }
};

class InvalidTypeException : public std::exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid type";
  }
};

int main(int argc, char *argv[])
{
  try
  {
    if (argc < 4)
    {
      throw InvalidArgumentsException();
    }

    const char *input = argv[1];
    const char *output = argv[2];
    const char *type = argv[3];

    if (strcmp(type, "-c") == 0)
    {
      // compress
      HuffmanCompression huffman = new HuffmanCompression();
      huffman.compress(input, output);
    }
    else if (strcmp(type, "-d") == 0)
    {
      // decompress
      HuffmanDecompression huffman = new HuffmanDecompression();
      huffman.decompress(input, output);
    }
    else
    {
      throw InvalidTypeException();
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}