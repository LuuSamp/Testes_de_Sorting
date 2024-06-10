#include <iostream>
#include "doubly_linkedlist.h"

using std::cout;
using std::endl;
using std::string;

// Lista duplamente encadeada
namespace dll
{
    Node<int>* createRandomList(int iLength, int start, int stop)
    {
        Node<int>* firstNode = createNode((rand()%(stop-start))+start);

        for(int i = 1; i < iLength; i++)
        {
            insertEnd(&firstNode, (rand()%(stop-start))+start);
        }

        return firstNode;
    }
}