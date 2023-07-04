//---------------------------------------------------------------------
// Arquivo      : List.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "List.hpp"

List::List()
{
  this->head = NULL;
  this->size = 0;
}

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

Node *List::removeHead()
{
  Node *temp = this->head;
  this->head = this->head->next;
  this->size--;
  return temp;
}

Node *List::getHead()
{
  return this->head;
}

int List::getSize()
{
  return this->size;
}

void List::printList()
{
  Node *current = this->head;

  while (current != NULL)
  {
    cout << current->character << " " << current->frequency << endl;
    current = current->next;
  }
}