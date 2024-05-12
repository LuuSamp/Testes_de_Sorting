#include <iostream>
#include "selectionSort.h"
#include "doubly_linkedlist.h"

void selectionSort(Node** head)
{
    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_1->iPayload > current_2->iPayload)
            {
                swapPayload(current_1, current_2);
            }
        }
    }
}