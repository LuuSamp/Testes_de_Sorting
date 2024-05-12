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
    Node* iInsertValueNode = *head;
    Node* iInnerLoopNode = *head;

    for (int iOuterLoop = 1; iOuterLoop < iLength; iOuterLoop++)
    {
        iInsertValueNode = iInsertValueNode -> ptrNext;
        iInnerLoopNode = iInsertValueNode -> ptrPrev;

        while (iInsertValueNode -> iPayload < iInnerLoopNode -> iPayload && iInnerLoopNode -> ptrPrev != nullptr)
        {
            iInnerLoopNode -> ptrNext -> iPayload = iInnerLoopNode -> iPayload;
            iInnerLoopNode = iInnerLoopNode -> ptrPrev;
        }

        iInnerLoopNode -> ptrNext -> iPayload = iInsertValueNode -> iPayload;
    }
}