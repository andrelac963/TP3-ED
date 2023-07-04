//---------------------------------------------------------------------
// Arquivo      : List.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "List.hpp"

// Construtor
List::List()
{
  this->head = NULL;
  this->size = 0;
}

// Destrutor que desaloca a lista
List::~List()
{
  Node *current = this->head;

  while (current != NULL)
  {
    Node *temp = current;
    current = current->next;
    delete temp;
  }
}

// Função que insere um nó na lista
void List::insert(Node *node)
{
  Node *current = this->head;
  Node *previous = NULL;

  while (current != NULL && current->frequency < node->frequency)
  {
    previous = current;
    current = current->next;
  }

  if (previous == NULL)
  {
    node->next = this->head;
    this->head = node;
  }
  else
  {
    previous->next = node;
    node->next = current;
  }

  this->size++;
}

// Função que preenche a lista com os caracteres e suas frequências
void List::fillList(unsigned int frequency[])
{
  for (int i = 0; i < TAM; i++)
  {
    if (frequency[i] > 0)
    {
      Node *node = new Node(i, frequency[i]);
      this->insert(node);
    }
  }
}

// Função que remove o primeiro nó da lista
Node *List::removeHead()
{
  Node *temp = this->head;
  this->head = this->head->next;
  this->size--;
  return temp;
}

// Função que retorna o primeiro nó da lista
Node *List::getHead()
{
  return this->head;
}

// Função que retorna o nó de um determinado índice
Node *List::getNode(int index)
{
  Node *current = this->head;

  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }

  return current;
}

// Função que retorna o tamanho da lista
int List::getSize()
{
  return this->size;
}

// Função que imprime a lista
void List::printList()
{
  Node *current = this->head;

  while (current != NULL)
  {
    cout << current->character << " : " << current->frequency << endl;
    current = current->next;
  }
}