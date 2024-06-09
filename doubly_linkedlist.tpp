#include <iostream>

using namespace std;

// Lista duplamente encadeada
namespace dll
{
    
    template <typename T>
    Node<T>* createNode(T iPayload)
    {
        Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));     
        temp->iPayload = iPayload;
        temp->ptrNext = nullptr;
        temp->ptrPrev = nullptr;

        return temp;
    }

    template <typename T>
    void displayList(Node<T>* node)
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

        Node<T>* temp = node;

        cout << "Payload: ";

        //Percorremos a lista até o fim (ptrNext do último é NULL) 
        while(temp != nullptr)
        {
            cout << temp->iPayload << " ";
            temp = temp->ptrNext;
        }

        cout << endl;
    }

    template <typename T>
    void insertFront(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = dll::createNode(iPayload);
        
        if (*head != nullptr)
        {
            (*head)->ptrPrev = newNode;
            newNode->ptrNext = (*head);
            (*head) = newNode;
            return;
        }
        
        (*head) = newNode;
        
    }

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = dll::createNode(iPayload);

        if (*head == nullptr)
        {
            (*head) = newNode;
            return;            
        }

        Node<T>* temp = (*head);

        //Percorremos a lista até o fim (ptrNext do último é NULL) 
        while (temp->ptrNext != nullptr) temp = temp->ptrNext;

        newNode->ptrPrev = temp; //newNode aponta para o fim da lista
        temp->ptrNext = newNode; //antigo último elemento aponta para o novo nó

    }

    template <typename T>
    void insertAfter(Node<T>* ptrLocation, T iPayLoad)
    {
        if (ptrLocation == nullptr)
        {
            cout << "Location é NULL" << endl;
        }
        
        Node<T>* newNode = dll::createNode(iPayLoad);
        
        // Corrigir nó a ser inserido
        newNode->ptrNext = ptrLocation->ptrNext;
        newNode->ptrPrev = ptrLocation;
        
        // Corrigir o ponto de inserção
        ptrLocation->ptrNext = newNode;
        
        if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
    }

    template <typename T>
    void deleteNode(Node<T>** head, Node<T>* ptrDelete)
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

    template <typename T>
    void clearList(Node<T>** head)
    {
        while(*head != nullptr) deleteNode(head, *head);
    }

    template <typename T>
    void swapPayload(Node<T>* node1, Node<T>* node2) 
    {
        int iTemp = node1->iPayload;
        node1->iPayload = node2->iPayload;
        node2->iPayload = iTemp;
    }

    template <typename T>
    T maxValue(Node<T>* head)
    {
        Node<T>* current = head;
        T maiorValor = head->iPayload;

        while (current != nullptr)
        {
            if (current->iPayload > maiorValor)
            {
                maiorValor = current->iPayload;
            }
            current = current->ptrNext;
        }
        return maiorValor;
    }
}