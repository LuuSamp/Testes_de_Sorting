#include <iostream>
#include "bubbleSort.h"
#include "doubly_linkedlist.h"

void bubbleSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = *head; current_2->ptrNext != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_2->iPayload > current_2->ptrNext->iPayload)
            {
                swapPayload(current_2, current_2->ptrNext);
            }
        }
    }
}

