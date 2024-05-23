#include <iostream>
#include "countingSort.h"
#include "doubly_linkedlist.h"

void countingSort(Node<int>** head)
{
    int maiorValor = maxValue(*head);
    int array[maiorValor+1] = {0};

    Node<int>* current1 = *head;
    int index = 0;

    while (current1 != nullptr)
    {
        index = current1->iPayload;
        array[index]++;
        current1 = current1->ptrNext;
    }

    Node<int>* current2 = *head;

    for (int i = 0; i <= maiorValor; i++)
    {
        for (int j = 0; j < array[i]; j++)
        {
            current2->iPayload = i;
            current2 = current2->ptrNext;
        }
    }
}