#include <iostream>
#include "doubly_linkedlist.h"

using namespace std;

namespace tree{
    template <typename T>
    Node<T>* createNode(T iValue)
    {
        Node<T>* tmp = (Node<T>*) malloc(sizeof(Node<T>));
        
        if (tmp == nullptr)
        {
            cerr << "Erro em createNode: malloc" << endl;
            exit(1);
        }
        
        tmp->iPayload = iValue;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
        
        return tmp;
    }

    template <typename T>
    Node<T>* insertNode(Node<T>* startingNode, T iData)
    {
        if(startingNode == nullptr)
        {
            return createNode(iData);
        }
        
        if(iData < startingNode->iPayload)
        {
            startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
        }
        else
        {
            startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
        }
        
        return startingNode;
    }

    template <typename T>
    int treeHeight(Node<T>* startingNode)
    {
        if (startingNode == nullptr) return 0;
        else
        {
            int iLeftHeight = treeHeight(startingNode->ptrLeft);
            int iRightHeight = treeHeight(startingNode->ptrRight);
            
            return max(iLeftHeight, iRightHeight) + 1;
        }
    }

    template <typename T>
    void bfsTraversal(Node<T>* startingNode)
    {
        if (startingNode == nullptr) return;
        
        Node<T>* nodeQueue[100];
        dll::Node<Node<T>*>* nodeQueueFront = dll::createNode(startingNode);
        dll::Node<Node<T>*>* nodeQueueRear = nodeQueueFront;

        int iQueueFront = 0;
        int iQueueRear = 1;
        
        iQueueRear++;
        
        while (nodeQueueFront != nullptr)
        {
            // currentNode recebe um Node de árvore, que é o iPayload do nosso dll:Node<Node<T>*>
            Node<T>* currentNode = nodeQueueFront -> iPayload;
            
            cout << currentNode->iPayload << " ";
            
            if (currentNode->ptrLeft != nullptr)
            {
                dll::insertAfter(nodeQueueRear, currentNode->ptrLeft);
                nodeQueueRear = nodeQueueRear -> ptrNext;
            }
            
            if (currentNode->ptrRight != nullptr)
            {
                dll::insertAfter(nodeQueueRear, currentNode->ptrRight);
                nodeQueueRear = nodeQueueRear -> ptrNext;
            }
            nodeQueueFront = nodeQueueFront -> ptrNext;
        }
    }

    template <typename T>
    Node<T>* dfsSearch(Node<T>* startingNode, T expectedValue)
    {
        if(startingNode == nullptr) return nullptr;
        else if(expectedValue == startingNode->iPayload) return startingNode;
        else if(expectedValue < startingNode->iPayload) return searchNode(startingNode->ptrLeft, expectedValue);
        else return searchNode(startingNode->ptrRight, expectedValue);
    }


    template <typename T>
    Node<T>* bfsSearch(Node<T>* startingNode, T expectedValue)
    {
        if (startingNode == nullptr) return nullptr;
        
        Node<T>* nodeQueue[100];
        dll::Node<Node<T>*>* nodeQueueFront = dll::createNode(startingNode);
        dll::Node<Node<T>*>* nodeQueueRear = nodeQueueFront;

        
        while (nodeQueueFront != nullptr)
        {
            // currentNode recebe um Node de árvore, que é o iPayload do nosso dll:Node<Node<T>*>
            Node<T>* currentNode = nodeQueueFront -> iPayload;
            
            if (currentNode -> iPayload == expectedValue)
            {
                return currentNode;
            }
            
            if (currentNode->ptrLeft != nullptr)
            {
                dll::insertAfter(nodeQueueRear, currentNode->ptrLeft);
                nodeQueueRear = nodeQueueRear -> ptrNext;
            }
            
            if (currentNode->ptrRight != nullptr)
            {
                dll::insertAfter(nodeQueueRear, currentNode->ptrRight);
                nodeQueueRear = nodeQueueRear -> ptrNext;
            }
            nodeQueueFront = nodeQueueFront -> ptrNext;
        }
        return nullptr;
    }
};