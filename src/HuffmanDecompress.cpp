//---------------------------------------------------------------------
// Arquivo      : HuffmanDecompress.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "HuffmanDecompress.hpp"

HuffmanDecompress::HuffmanDecompress()
{
}

HuffmanDecompress::~HuffmanDecompress()
{
}

Dictionary *HuffmanDecompress::readDictionary(const char *input)
{
  ifstream dictionaryFile(input);

  if (dictionaryFile.is_open())
  {
    string line;
    getline(dictionaryFile, line);
    int rows = stoi(line);
    Dictionary *dictionary = new Dictionary(rows);

    for (int i = 0; i < rows; i++)
    {
      getline(dictionaryFile, line);
      dictionary->setCode(i, line);
    }

    dictionaryFile.close();

    return dictionary;
  }
  else
  {
    throw FailedToOpenFile(input);
  }
}

string HuffmanDecompress::decode(Dictionary *dictionary, const char *input)
{
}

void HuffmanDecompress::decompress(const char *input, const char *output)
{
  Dictionary *dictionary = this->readDictionary("./bin/dictionary.txt");

  dictionary->printDictionary();
}