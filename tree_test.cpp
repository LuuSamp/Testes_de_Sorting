#include <iostream>
#include "tree.h"

using namespace tree;

int main()
{
    Node<int>* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    cout << "Tree Height: " << treeHeight(root) << endl;
    
    return 0;
    return 0;
}
/*
void bfsTraversal(Node<int>* startingNode)
{
    if (startingNode == nullptr) return;
    
    // Parte 1 do Trabalho: Alterar para Lista Encadeada
    Node<int>* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
    
    while (iQueueFront < iQueueRear)
    {
        Node<int>* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout << currentNode->iPayload << " ";
        
        if (currentNode->ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
        
    }
}
*/
