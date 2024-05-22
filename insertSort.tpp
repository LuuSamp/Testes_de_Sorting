#include <iostream>
#include "doubly_linkedlist.h"

template<typename T>
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

template<typename T>
void insertSort(Node<T>** head)
{
    int iInsertValue = 0;
    Node<T>* InnerLoopNode = (*head);

    for (Node<T>* OuterLoopNode = (*head) -> ptrNext; OuterLoopNode != nullptr; OuterLoopNode = OuterLoopNode -> ptrNext)
    {
        iInsertValue = OuterLoopNode -> iPayload;
        InnerLoopNode = OuterLoopNode -> ptrPrev;

        while (iInsertValue < InnerLoopNode -> iPayload)
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