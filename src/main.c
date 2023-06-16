//---------------------------------------------------------------------
// Arquivo      : main.c
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "List.h"

#define TAM 256

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "Portuguese");

  if (argc != 4)
  {
    printf("Uso: %s <arquivo_entrada> <arquivo_saida> <opção>\n", argv[0]);
    return 1;
  }

  const char *option = argv[3];

  if (!strcmp(option, "-c"))
  {
    unsigned int frequency[TAM] = {0};

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
      printf("Erro ao abrir o arquivo %s\n", argv[1]);
      return 1;
    }

    for (int c = fgetc(input); c != EOF; c = fgetc(input))
    {
      frequency[c]++;
    }

    fclose(input);

    List list;
    InitList(&list);
    fillList(&list, frequency);
    Node *rootTree = createTree(&list);

    int rows = heightTree(rootTree) + 1;
    char **dictionary = createDictionary(rows);
    fillDictionary(rootTree, dictionary, "", rows);
    printDictionary(dictionary);

    FILE *output = fopen(argv[2], "w");

    if (output == NULL)
    {
      printf("Erro ao abrir o arquivo %s\n", argv[2]);
      return 1;
    }

    fclose(output);
  }
  else if (!strcmp(option, "-d"))
  {
    printf("Descomprimir\n");
  }
  else
  {
    printf("Opção inválida!\n");
    return 1;
  }

  return 0;
}