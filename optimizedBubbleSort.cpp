#include <iostream>
#include "optimizedBubbleSort.h"
#include "doubly_linkedlist.h"

void optimizedBubbleSort(Node** head, int iLength)
{
    bool bUnordered = false;

    for (int iOuterLoop = iLength-1; iOuterLoop > 0; iOuterLoop--)
    {
        bUnordered = false;

        Node* current_2 = *head;
        for (int iInnerLoop = 0; iInnerLoop < iOuterLoop; iInnerLoop++)
        {

            if (current_2->iPayload > current_2->ptrNext->iPayload)
            {
                swapPayload(current_2, current_2->ptrNext);
                bUnordered = true;
            }
            current_2 = current_2->ptrNext;
        }

        if (bUnordered == false) break;
    }
}