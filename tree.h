#ifndef TREE_H
#define TREE_H

namespace tree
{
    template <typename T>
    struct Node
    {
        T iPayload;
        Node<T>* ptrLeft;
        Node<T>* ptrRight;
    };
    tree::Node<int>* createRandomTree(int, int, int);
}

#include "tree.tpp"

#endif