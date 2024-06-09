#include <iostream>
#include "countingSort.h"
#include "doubly_linkedlist.h"

using namespace dll;

void countingSort(Node<int>** head)
{
    int maiorValor = maxValue(*head);

    Node<int>* fno = nullptr;

    int quantity = 0;

    for(int i = 0; i <= maiorValor; i++)
    {
    quantity = 0;
    Node<int>* current = *head;
        while (current != nullptr)
        {
            if(current->iPayload == i) quantity++;
            current = current->ptrNext;
        }
    insertEnd(&fno, quantity);
    }

    Node<int>* current1 = *head;
    Node<int>* current2 = fno;

    for (int i = 0; i <= maiorValor; i++)
    {
        for (int j = 0; j < current2 -> iPayload; j++)
        {
            current1 -> iPayload = i;
            current1 = current1->ptrNext;
        }
        current2 = current2 -> ptrNext;
    }
    clearList(&fno);
}