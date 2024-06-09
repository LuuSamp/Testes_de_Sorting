#include <iostream>
#include "doubly_linkedlist.h"

using namespace dll;

template<typename T>
void selectionSort(Node<T>** head)
{
    for (Node<T>* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        for (Node<T>* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
        {
            if (current_1->iPayload > current_2->iPayload)
            {
                swapPayload(current_1, current_2);
            }
        }
    }
}

template<typename T>
void optimizedSelectionSort(Node<T>** head)
{
    T iMinValue = 0;
    Node<T>* swapNode = nullptr;

    for (Node<T>* current_1 = *head; current_1 != nullptr; current_1 = current_1->ptrNext)
    {
        iMinValue = current_1 -> iPayload;
        swapNode = current_1;

        for (Node<T>* current_2 = current_1->ptrNext; current_2 != nullptr; current_2 = current_2->ptrNext)
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