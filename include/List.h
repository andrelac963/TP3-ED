//---------------------------------------------------------------------
// Arquivo      : List.h
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define TAM 256

typedef struct node
{
  unsigned char character;
  unsigned int frequency;
  struct node *left, *right, *next;
} Node;

typedef struct list
{
  Node *head;
  unsigned int size;
} List;

void InitList(List *list);
void insertList(List *list, Node *node);
void fillList(List *list, unsigned int frequency[]);
void printList(List *list);
Node *removeHead(List *list);
Node *createTree(List *list);
void printTree(Node *root, unsigned int height);
int heightTree(Node *root);
char **createDictionary(int height);
void fillDictionary(Node *root, char **dictionary, char *code, int rows);
void printDictionary(char **dictionary);

#endif