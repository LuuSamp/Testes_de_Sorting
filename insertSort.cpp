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

void insertSort(Node** head)
{
    int iInsertValue = 0;
    Node* InnerLoopNode = (*head);

    for (Node* OuterLoopNode = (*head) -> ptrNext; OuterLoopNode != nullptr; OuterLoopNode = OuterLoopNode -> ptrNext)
    {
        iInsertValue = OuterLoopNode -> iPayload;
        InnerLoopNode = OuterLoopNode -> ptrPrev;

        while (iInsertValue < InnerLoopNode -> iPayload && InnerLoopNode != nullptr)
        {
            InnerLoopNode -> ptrNext -> iPayload = InnerLoopNode -> iPayload;
            
            InnerLoopNode = InnerLoopNode -> ptrPrev;

            if(InnerLoopNode == nullptr)
            {
                break;
            } 
        }

        if(InnerLoopNode == nullptr)
        {
            (*head) -> iPayload = iInsertValue;
        }
        else
        {
        InnerLoopNode -> ptrNext -> iPayload = iInsertValue;
        }
    }
}