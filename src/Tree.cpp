//---------------------------------------------------------------------
// Arquivo      : Tree.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "Tree.hpp"

// Construtor
Tree::Tree()
{
  this->root = NULL;
}

// Destrutor
Tree::~Tree()
{
  delete this->root;
}

// Função que constrói a árvore de Huffman a partir de uma lista
void Tree::buildTree(List *list)
{
  Node *node1, *node2, *node3;

  while (list->getSize() > 1)
  {
    // Remove os dois nós de menor frequência da lista
    node1 = list->removeHead();
    node2 = list->removeHead();

    // Cria um novo nó com os dois nós removidos como filhos
    node3 = new Node('*', node1->frequency + node2->frequency);

    node3->left = node1;
    node3->right = node2;

    // Insere o novo nó na lista
    list->insert(node3);
  }

  // Seta a raiz da árvore
  this->root = list->removeHead();
}

// Função que seta a raiz da árvore
void Tree::setRoot(Node *root)
{
  this->root = root;
}

// Função que retorna a raiz da árvore
Node *Tree::getRoot()
{
  return this->root;
}

// Função que retorna a altura da árvore
int Tree::getHeight(Node *root)
{
  int leftHeight, rightHeight;

  if (root == NULL)
  {
    return -1;
  }
  else
  {
    // Chama a função recursivamente para os filhos
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);

    // Retorna a altura do maior filho + 1
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

// Função que imprime a árvore
void Tree::printTree(Node *root, int height)
{
  if (root->left == NULL && root->right == NULL)
  {
    cout << root->character << " : " << height << endl;
  }
  else
  {
    printTree(root->left, height + 1);
    printTree(root->right, height + 1);
  }
}