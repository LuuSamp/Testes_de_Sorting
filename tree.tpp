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
    Node<T>* lesserLeaf(Node<T>* startingNode)
    {
        Node<T>* ptrCurrent = startingNode;
    
        while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
        
        return ptrCurrent;
    }

    template <typename T>
    Node<T>* deleteNode(Node<T>* startingNode, T iData)
    {
        if (startingNode == nullptr) return nullptr;
        
        if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
        else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
        else
        {
            Node<T>* ptrTemp = nullptr;
            
            if (startingNode->ptrLeft == nullptr)
            {
                ptrTemp = startingNode->ptrRight;
                free(startingNode);
                return ptrTemp;
            }
            else if (startingNode->ptrRight == nullptr)
            {
                ptrTemp = startingNode->ptrLeft;
                free(startingNode);
                return ptrTemp;            
            }
            
            ptrTemp = lesserLeaf(startingNode->ptrRight);
            
            startingNode->iPayload = ptrTemp->iPayload;
            
            startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
        }
        
        return startingNode;
    }

    template <typename T>
    void clearTree(Node<T>** root)
    {
        while(*root != nullptr)
        {
            tree::deleteNode(*root, (*root) -> iPayload);
        }
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
        
        dll::Node<Node<T>*>* nodeQueueHead = dll::createNode(startingNode);
        dll::Node<Node<T>*>* nodeQueueFront = nodeQueueHead;
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
        
        dll::clearList(&nodeQueueHead);
    }

    template <typename T>
    Node<T>* bfsSearch(Node<T>* startingNode, T expectedValue)
    {
        if (startingNode == nullptr) return nullptr;
        
        dll::Node<Node<T>*>* nodeQueueHead = dll::createNode(startingNode);
        dll::Node<Node<T>*>* nodeQueueFront = nodeQueueHead;
        dll::Node<Node<T>*>* nodeQueueRear = nodeQueueFront;

        
        while (nodeQueueFront != nullptr)
        {
            // currentNode recebe um Node de árvore, que é o iPayload do nosso dll:Node<Node<T>*>
            Node<T>* currentNode = nodeQueueFront -> iPayload;
            
            if (currentNode -> iPayload == expectedValue)
            {
                dll::clearList(&nodeQueueHead);
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
        dll::clearList(&nodeQueueHead);
        return nullptr;
    }

    template <typename T>
    Node<T>* dfsSearch(Node<T>* startingNode, T expectedValue)
    {
        if(startingNode == nullptr) return startingNode;
        if(startingNode -> iPayload == expectedValue) return startingNode;
        Node<T>* left = dfsSearch(startingNode -> ptrLeft, expectedValue);
        if(left != nullptr) return left;
        else return dfsSearch(startingNode -> ptrRight, expectedValue);
        
    }
};