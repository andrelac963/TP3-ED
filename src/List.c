#include "List.h"

void InitList(List *list)
{
  list->head = NULL;
  list->size = 0;
}

void insertList(List *list, Node *node)
{
  if (list->head == NULL)
  {
    list->head = node;
  }
  else if (node->frequency <= list->head->frequency)
  {
    node->next = list->head;
    list->head = node;
  }
  else
  {
    Node *current = list->head;
    while (current->next != NULL && current->next->frequency < node->frequency)
    {
      current = current->next;
    }
    node->next = current->next;
    current->next = node;
  }

  list->size++;
}

void fillList(List *list, unsigned int frequency[])
{
  Node *node;

  for (int i = 0; i < TAM; i++)
  {
    if (frequency[i] > 0)
    {
      node = (Node *)malloc(sizeof(Node));
      if (node == NULL)
      {
        printf("Erro ao alocar memória!\n");
        exit(1);
      }

      node->character = i;
      node->frequency = frequency[i];
      node->left = NULL;
      node->right = NULL;
      node->next = NULL;

      insertList(list, node);
    }
  }
}

void printList(List *list)
{
  Node *current = list->head;
  while (current != NULL)
  {
    printf("%c: %u\n", current->character, current->frequency);
    current = current->next;
  }
}

Node *removeHead(List *list)
{
  Node *node = list->head;
  list->head = list->head->next;
  list->size--;
  return node;
}

Node *createTree(List *list)
{
  Node *first, *second, *aux;

  while (list->size > 1)
  {
    first = removeHead(list);
    second = removeHead(list);

    aux = (Node *)malloc(sizeof(Node));
    if (aux == NULL)
    {
      printf("Erro ao alocar memória!\n");
      exit(1);
    }

    aux->character = 0;
    aux->frequency = first->frequency + second->frequency;
    aux->left = first;
    aux->right = second;
    aux->next = NULL;

    insertList(list, aux);
  }

  return removeHead(list);
}

void printTree(Node *root, unsigned int height)
{
  if (root->left == NULL && root->right == NULL)
  {
    printf("%c: %u\n", root->character, height);
  }
  else
  {
    printTree(root->left, height + 1);
    printTree(root->right, height + 1);
  }
}

int heightTree(Node *root)
{
  int leftHeight, rightHeight;

  if (root == NULL)
  {
    return -1;
  }
  else
  {
    leftHeight = heightTree(root->left);
    rightHeight = heightTree(root->right);

    if (leftHeight < rightHeight)
    {
      return rightHeight + 1;
    }
    else
    {
      return leftHeight + 1;
    }
  }
}

char **createDictionary(int height)
{
  char **dictionary = (char **)malloc(TAM * sizeof(char *));
  if (dictionary == NULL)
  {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  for (int i = 0; i < TAM; i++)
  {
    dictionary[i] = calloc(height, sizeof(char));
    if (dictionary[i] == NULL)
    {
      printf("Erro ao alocar memória!\n");
      exit(1);
    }
  }

  return dictionary;
}

void fillDictionary(Node *root, char **dictionary, char *code, int rows)
{
  char left[rows], right[rows];

  if (root->left == NULL && root->right == NULL)
  {
    strcpy(dictionary[root->character], code);
  }
  else
  {
    strcpy(left, code);
    strcpy(right, code);

    strcat(left, "0");
    strcat(right, "1");

    fillDictionary(root->left, dictionary, left, rows);
    fillDictionary(root->right, dictionary, right, rows);
  }
}

void printDictionary(char **dictionary)
{
  for (int i = 0; i < TAM; i++)
  {
    if (strlen(dictionary[i]) > 0)
      printf("\t%3d: %s\n", i, dictionary[i]);
  }
}