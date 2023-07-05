//---------------------------------------------------------------------
// Arquivo      : HuffmanDecompress.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-07-04 - arquivo finalizado
//---------------------------------------------------------------------

#include "HuffmanDecompress.hpp"

// Construtor
HuffmanDecompress::HuffmanDecompress()
{
}

// Destrutor
HuffmanDecompress::~HuffmanDecompress()
{
}

// Lê o arquivo de índice e conta a frequência de cada caractere
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

// Retorna se o bit i está setado no byte
unsigned int isBitSet(unsigned char byte, int i)
{
  unsigned char mask = 1 << i;
  return mask & byte;
}

// Decodifica o arquivo de entrada e escreve no arquivo de saída
void HuffmanDecompress::decode(const char *input, const char *output, Node *root)
{
  // Abre o arquivo de entrada e o arquivo de saída
  FILE *fileIn = fopen(input, "rb");
  FILE *fileOut = fopen(output, "w");

  // Variável auxiliar para percorrer a árvore
  unsigned char byte;
  Node *aux = root;

  if (fileIn && fileOut)
  {

    while (fread(&byte, sizeof(unsigned char), 1, fileIn))
    {
      for (int i = 7; i >= 0; i--)
      {
        // Percorre a árvore de acordo com o bit i do byte
        if (isBitSet(byte, i))
        {
          aux = aux->right;
        }
        else
        {
          aux = aux->left;
        }

        // Se o nó atual for uma folha, escreve o caractere no arquivo de saída
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
  // Lê o arquivo de índice e conta a frequência de cada caractere
  this->readIndex("./temp/index.txt");

  List *list = new List();

  // Preenche a lista de nós com os caracteres e suas frequências
  list->fillList(this->frequency);

  Tree *tree = new Tree();

  // Constroi a árvore de Huffman
  tree->buildTree(list);

  // Decodifica o arquivo de entrada e escreve no arquivo de saída usando a árvore de Huffman
  this->decode(input, output, tree->getRoot());

  delete list;
  delete tree;
}