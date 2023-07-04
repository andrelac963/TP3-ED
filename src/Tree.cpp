//---------------------------------------------------------------------
// Arquivo      : Tree.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "Tree.hpp"

Tree::Tree()
{
  this->root = NULL;
}

Tree::~Tree()
{
  delete this->root;
}

void Tree::buildTree(List *list)
{
  Node *node1, *node2, *node3;

  while (list->getSize() > 1)
  {
    node1 = list->removeHead();
    node2 = list->removeHead();

    node3 = new Node('*', node1->frequency + node2->frequency);

    node3->left = node1;
    node3->right = node2;

    list->insert(node3);
  }

  this->root = list->removeHead();
}

void Tree::setRoot(Node *root)
{
  this->root = root;
}

Node *Tree::getRoot()
{
  return this->root;
}

int Tree::getHeight(Node *root)
{
  int leftHeight, rightHeight;

  if (root == NULL)
  {
    return -1;
  }
  else
  {
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);

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