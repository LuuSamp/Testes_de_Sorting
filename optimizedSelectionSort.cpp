#include <iostream>
#include "optimizedSelectionSort.h"
#include "doubly_linkedlist.h"

void optimizedSelectionSort(Node** head)
{
    int iMinValue = 0;
    Node* swapNode = nullptr;

    for (Node* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        iMinValue = current_1 -> iPayload;
        swapNode = current_1;

        for (Node* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (iMinValue > current_2 -> iPayload)
            {
                iMinValue = current_2->iPayload;
                swapNode = current_2;
            }
        }
        swapPayload(current_1, swapNode);
    }
}