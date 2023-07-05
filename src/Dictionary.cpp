//---------------------------------------------------------------------
// Arquivo      : Dictionary.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "Dictionary.hpp"

// Construtor que aloca a matriz de caracteres
Dictionary::Dictionary(int rows)
{
  this->dictionary = new char *[TAM];

  // Inicializa a matriz de caracteres com strings vazias
  for (int i = 0; i < TAM; i++)
  {
    this->dictionary[i] = new char[rows];
    strcpy(this->dictionary[i], "");
  }
}

// Destrutor que desaloca a matriz de caracteres
Dictionary::~Dictionary()
{
  for (int i = 0; i < TAM; i++)
  {
    delete[] this->dictionary[i];
  }

  delete[] this->dictionary;
}

// Função que preenche a matriz de caracteres com os códigos da árvore de Huffman
void Dictionary::fillDictionary(Node *root, char *code, int rows)
{
  // Se o nó não for uma folha, chama a função recursivamente para os filhos
  if (root->left != NULL)
  {
    char *codeLeft = new char[rows];
    strcpy(codeLeft, code);
    strcat(codeLeft, "0");
    this->fillDictionary(root->left, codeLeft, rows);
  }

  // Se o nó não for uma folha, chama a função recursivamente para os filhos
  if (root->right != NULL)
  {
    char *codeRight = new char[rows];
    strcpy(codeRight, code);
    strcat(codeRight, "1");
    this->fillDictionary(root->right, codeRight, rows);
  }

  // Se o nó for uma folha, seta o código do caractere
  if (root->left == NULL && root->right == NULL)
  {
    strcpy(this->dictionary[root->character], code);
  }
}

// Função que retorna o código de um caractere
char *Dictionary::getCode(unsigned char character)
{
  return this->dictionary[character];
}

// Função que seta o código de um caractere
void Dictionary::setCode(unsigned char character, string code)
{
  strcpy(this->dictionary[character], code.c_str());
}

// Função que imprime a matriz de caracteres
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