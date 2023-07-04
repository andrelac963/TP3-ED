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

void HuffmanDecompress::readIndex(const char *input)
{
  ifstream file(input);

  if (file.is_open())
  {
    unsigned int character;
    unsigned int freq;

    // Percorre o arquivo de entrada e conta a frequência de cada caractere
    while (file >> character >> freq)
    {
      this->frequency[character] = freq;
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile(input);
  }
}

unsigned int isBitSet(unsigned char byte, int i)
{
  unsigned char mask = 1 << i;
  return mask & byte;
}

void HuffmanDecompress::decode(const char *input, const char *output, Node *root)
{
  FILE *fileIn = fopen(input, "rb");
  FILE *fileOut = fopen(output, "w");

  unsigned char byte;
  Node *aux = root;

  if (fileIn && fileOut)
  {
    while (fread(&byte, sizeof(unsigned char), 1, fileIn))
    {
      for (int i = 7; i >= 0; i--)
      {
        if (isBitSet(byte, i))
        {
          aux = aux->right;
        }
        else
        {
          aux = aux->left;
        }

        if (aux->left == NULL && aux->right == NULL)
        {
          fprintf(fileOut, "%c", aux->character);
          aux = root;
        }
      }
    }

    fclose(fileIn);
    fclose(fileOut);
  }
  else
  {
    throw FailedToOpenFile(input);
  }
}

void HuffmanDecompress::decompress(const char *input, const char *output)
{
  this->readIndex("./bin/index.txt");

  List *list = new List();

  list->fillList(this->frequency);

  Tree *tree = new Tree();

  tree->buildTree(list);

  this->decode(input, output, tree->getRoot());

  delete list;
  delete tree;
}