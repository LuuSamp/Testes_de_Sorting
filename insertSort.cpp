#include <iostream>
#include "insertSort.h"
#include "doubly_linkedlist.h"

void insertSort(int arriNumbers[], int iLength)
{
    int iInsertValue = 0;
    int iInnerLoop = 0;

    for (int iOuterLoop = 1; iOuterLoop < iLength; iOuterLoop++)
    {
        iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;

        while (iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0)
        {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }

        arriNumbers[iInnerLoop + 1] = iInsertValue;
    }
}

void insertSort(Node** head, int iLength)
{
    Node* iInsertValueNode = (*head);
    Node* iInnerLoopNode = (*head);
    int iInsertValue;

    for (int iOuterLoop = 1; iOuterLoop < iLength; iOuterLoop++)
    {
        iInsertValueNode = iInsertValueNode -> ptrNext;
        iInsertValue = iInsertValueNode -> iPayload;
        iInnerLoopNode = iInsertValueNode -> ptrPrev;

        while (iInsertValue < iInnerLoopNode -> iPayload && iInnerLoopNode != nullptr)
        {
            iInnerLoopNode -> ptrNext -> iPayload = iInnerLoopNode -> iPayload;
            
            iInnerLoopNode = iInnerLoopNode -> ptrPrev;

            if(iInnerLoopNode == nullptr)
            {
                break;
            } 
        }

        if(iInnerLoopNode == nullptr)
        {
            (*head) -> iPayload = iInsertValue;
        }
        else
        {
        iInnerLoopNode -> ptrNext -> iPayload = iInsertValue;
        }
    }
}