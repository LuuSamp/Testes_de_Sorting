#include <iostream>
#include "doubly_linkedlist.h"

using std::cout;
using std::endl;
using std::string;

// Lista duplamente encadeada

Node<int>* createRandomList(int iLength)
{
    Node<int>* firstNode = createNode((rand()%100)+1);

    for(int i = 1; i < iLength; i++)
    {
        insertEnd(&firstNode, (rand()%100)+1);
    }

    return firstNode;
}