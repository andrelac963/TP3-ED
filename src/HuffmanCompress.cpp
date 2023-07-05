//---------------------------------------------------------------------
// Arquivo      : HuffmanCompress.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "HuffmanCompress.hpp"

// Construtor
HuffmanCompress::HuffmanCompress()
{
}

// Destrutor
HuffmanCompress::~HuffmanCompress()
{
}

// Conta a frequência de cada caractere no arquivo de entrada
void HuffmanCompress::countFrequency(const char *input)
{
  ifstream file(input);

  if (file.is_open())
  {
    unsigned char character;

    // Percorre o arquivo de entrada e conta a frequência de cada caractere
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

// Retorna a string de código de cada caractere do arquivo de entrada codificado
string HuffmanCompress::encode(Dictionary *dictionary, const char *input)
{
  string code = "";

  ifstream file(input);

  if (file.is_open())
  {
    unsigned char character;

    // Percorre o arquivo de entrada e concatena o código de cada caractere
    while (file.get((char &)character))
    {
      code += dictionary->getCode(character);
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile(input);
  }

  return code;
}

// Salva o arquivo de saída com o código do arquivo de entrada codificado em binário
void HuffmanCompress::saveCompressedFile(const char *output, string code)
{
  ofstream file(output, ios::binary);

  if (file.is_open())
  {
    // Usa um byte para armazenar o código binário e uma mascara para setar os bits
    int j = 7;
    unsigned char mask, byte = 0;

    int size = code.length();

    for (int i = 0; i < size; i++)
    {
      mask = 1;

      // Se o bit for 1, seta o bit na posição j
      if (code[i] == '1')
      {
        mask = mask << j;
        byte = byte | mask;
      }
      j--;

      // Se o byte estiver completo, salva no arquivo de saída
      if (j < 0)
      {
        file << byte;
        j = 7;
        byte = 0;
      }
    }
    // Se o byte não estiver completo, salva no arquivo de saída
    if (j >= 0)
    {
      file << byte;
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile(output);
  }
}

// Salva a lista de caracteres e suas frequências no arquivo de saída
void HuffmanCompress::saveIndex(const char *output)
{
  ofstream file(output);

  if (file.is_open())
  {
    for (int i = 0; i < TAM; i++)
    {
      // Se o caractere tiver frequência maior que 0, salva no arquivo de saída
      if (frequency[i] > 0)
      {
        file << i << " " << frequency[i] << endl;
      }
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile(output);
  }
}

// Comprime o arquivo de entrada e salva o arquivo de saída
void HuffmanCompress::compress(const char *input, const char *output)
{
  // Contando a frequência de cada caractere
  this->countFrequency(input);

  // Salvando a lista no arquivo de saída
  this->saveIndex("./temp/index.txt");

  List *list = new List();

  // Preenchendo a lista com os caracteres e suas frequências
  list->fillList(this->frequency);

  Tree *tree = new Tree();

  // Construindo a árvore de Huffman a partir da lista
  tree->buildTree(list);

  int rows = tree->getHeight(tree->getRoot()) + 1;

  Dictionary *dictionary = new Dictionary(rows);

  // Preenchendo o dicionário com os códigos de cada caractere
  dictionary->fillDictionary(tree->getRoot(), "", rows);

  // Codificando o arquivo de entrada
  string code = this->encode(dictionary, input);

  // Salvando o código do arquivo de entrada no arquivo de saída
  this->saveCompressedFile(output, code);

  delete list;
  delete tree;
  delete dictionary;
}