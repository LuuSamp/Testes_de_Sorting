#include <iostream>
#include "doubly_linkedlist.h"

using std::cout;
using std::endl;
using std::string;

// Lista duplamente encadeada

struct Node;

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));     
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Nao foi possivel realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio da Lista: Nao foi possivel realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
	// newNode->ptrPrev = nullptr;
	
	if (*head != nullptr)
	{
		(*head)->ptrPrev = newNode;
		newNode->ptrNext = (*head);
		(*head) = newNode;
		return;
	}
	
	(*head) = newNode;
	
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    //newNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        //newNode->ptrPrev = nullptr;   
        (*head) = newNode;
        return;            
    }

    Node* temp = (*head);

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; //antigo último elemento aponta para o novo nó

}

void insertAfter(Node* ptrLocation, int iPayLoad)
{
	if (ptrLocation == nullptr)
	{
		cout << "Location é NULL" << endl;
	}
	
	Node* newNode = createNode(iPayLoad);
	
	// Corrigir nó a ser inserido
	newNode->ptrNext = ptrLocation->ptrNext;
	newNode->ptrPrev = ptrLocation;
	
	// Corrigir o ponto de inserção
	ptrLocation->ptrNext = newNode;
	
	if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
	if (*head == nullptr || ptrDelete == nullptr)
	{
		cout << " Não foi possível remover." << endl;
		return;
	}
	
	// Caso o ptrDelete seja o primeiro elemento da lista
	if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;
	
	// Se o ptrDelete não é o último nó
	if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

	// Se o ptrDelete não é o primeiro nó
	if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
	
	free(ptrDelete);
}










