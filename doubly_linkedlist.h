#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

namespace dll
{
    template <typename T>
    struct Node
    {
        T iPayload;
        Node<T>* ptrNext;
        Node<T>* ptrPrev;
    };

    template <typename T>
    Node<T>* createNode(T);

    template <typename T>
    void insertFront(Node<T>**, T);

    template <typename T>
    void insertEnd(Node<T>**, T);

    template <typename T>
    void deleteNode(Node<T>**, Node<T>*);

    template <typename T>
    void displayList(Node<T>*);

    Node<int>* createRandomList(int);

    template <typename T>
    void swapPayload(Node<T>*, Node<T>*); 

    template <typename T>
    T maxValue(Node<T>*);
}
#include "doubly_linkedlist.tpp"

#endif