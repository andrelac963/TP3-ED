//---------------------------------------------------------------------
// Arquivo      : HuffmanCompress.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "HuffmanCompress.hpp"

HuffmanCompress::HuffmanCompress()
{
}

HuffmanCompress::~HuffmanCompress()
{
}

void HuffmanCompress::CountFrequency(const char *input)
{
  ifstream file(input);

  if (file.is_open())
  {
    unsigned char character;

    while (file.get((char &)character))
    {
      frequency[character]++;
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile(input);
  }
}

void HuffmanCompress::Compress(const char *input, const char *output)
{
  this->CountFrequency(input);

  List *list = new List();

  list->fillList(this->frequency);

  Tree *tree = new Tree();

  tree->buildTree(list);

  int rows = tree->getHeight(tree->getRoot()) + 1;

  Dictionary *dictionary = new Dictionary(rows);

  dictionary->fillDictionary(tree->getRoot(), "", rows);

  delete list;
  delete tree;

  ifstream inputFile(input);

  if (inputFile.is_open())
  {
    ofstream outputFile(output);

    if (outputFile.is_open())
    {
      char character;
      while (inputFile.get(character))
      {
        string code = dictionary->getCode(character);
        for (char bit : code)
        {
          if (bit == '0')
          {
            // Escrever bit 0 no arquivo de saída
            outputFile.put(0);
          }
          else if (bit == '1')
          {
            // Escrever bit 1 no arquivo de saída
            outputFile.put(1);
          }
          else
          {
            // Tratar erro, caractere inválido no dicionário
          }
        }
      }

      outputFile.close();
    }
    else
    {
      throw FailedToOpenFile(output);
    }

    inputFile.close();
  }
  else
  {
    throw FailedToOpenFile(input);
  }
}