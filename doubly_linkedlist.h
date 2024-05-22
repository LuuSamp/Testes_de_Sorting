#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include "doubly_linkedlist.tpp"

template <typename T>
struct Node
{
    T iPayload;
    Node<T>* ptrNext;
    Node<T>* ptrPrev;
};

template <typename T>
Node<T>* createNode(int);

template <typename T>
void insertFront(Node<T>**, int);

template <typename T>
void insertEnd(Node<T>**, int);

template <typename T>
void deleteNode(Node<T>**, Node<T>*);

template <typename T>
void displayList(Node<T>*);

template <typename T>
Node<T>* createRandomList(int);

template <typename T>
void swapPayload(Node<T>*, Node<T>*); 

template <typename T>
int maxValue(Node<T>*);

#endif