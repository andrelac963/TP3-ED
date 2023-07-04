//---------------------------------------------------------------------
// Arquivo      : Dictionary.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "Dictionary.hpp"

Dictionary::Dictionary(int rows)
{
  this->dictionary = new char *[TAM];

  for (int i = 0; i < TAM; i++)
  {
    this->dictionary[i] = new char[rows];
    strcpy(this->dictionary[i], "");
  }
}

Dictionary::~Dictionary()
{
  for (int i = 0; i < TAM; i++)
  {
    delete[] this->dictionary[i];
  }

  delete[] this->dictionary;
}

void Dictionary::fillDictionary(Node *root, char *code, int rows)
{
  if (root->left != NULL)
  {
    char *codeLeft = new char[rows];
    strcpy(codeLeft, code);
    strcat(codeLeft, "0");
    this->fillDictionary(root->left, codeLeft, rows);
  }

  if (root->right != NULL)
  {
    char *codeRight = new char[rows];
    strcpy(codeRight, code);
    strcat(codeRight, "1");
    this->fillDictionary(root->right, codeRight, rows);
  }

  if (root->left == NULL && root->right == NULL)
  {
    strcpy(this->dictionary[root->character], code);
  }
}

int Dictionary::sizeText(unsigned char *text)
{
  int i = 0;
  int size = 0;
  while (text[i] != '\0')
  {
    size += strlen(this->dictionary[text[i]]);
    i++;
  }
  return size;
}

char *Dictionary::getCode(unsigned char character)
{
  return this->dictionary[character];
}

void Dictionary::printDictionary()
{
  for (int i = 0; i < TAM; i++)
  {
    if (strcmp(this->dictionary[i], "") != 0)
    {
      cout << i << " : " << this->dictionary[i] << endl;
    }
  }
}