#include <iostream>

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

typedef struct LinkedList 
{
    Node* treeNode;
    LinkedList* ptrNext;
} LinkedList;

Node* createNode(int);
void addToList(LinkedList*&, LinkedList*&, Node*); 
Node* removeFromList(LinkedList*&, LinkedList*&); 
void bfsTraversal(Node*); 

int main() 
{
    Node* root = createNode(5);
    root->ptrLeft = createNode(3);
    root->ptrRight = createNode(7);
    root->ptrLeft->ptrLeft = createNode(2);
    root->ptrLeft->ptrRight = createNode(5);
    root->ptrRight->ptrLeft = createNode(6);
    root->ptrRight->ptrRight = createNode(10);

    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;

    return 0;
}

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    
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

void addToList(LinkedList*& front, LinkedList*& rear, Node* treeNode) 
{
    LinkedList* newNode = (LinkedList*) malloc(sizeof(LinkedList));
    newNode->treeNode = treeNode;
    newNode->ptrNext = nullptr;

    if (rear == nullptr) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->ptrNext = newNode;
        rear = newNode;
    }
}

Node* removeFromList(LinkedList*& front, LinkedList*& rear) 
{
    if (front == nullptr) 
    {
        return nullptr;
    }

    LinkedList* temp = front;
    front = front->ptrNext;

    if (front == nullptr) 
    {
        rear = nullptr;
    }

    Node* treeNode = temp->treeNode;
    free(temp);

    return treeNode;
}

void bfsTraversal(Node* startingNode) 
{
    if (startingNode == nullptr) return;

    LinkedList* front = nullptr;
    LinkedList* rear = nullptr;

    addToList(front, rear, startingNode);

    while (front != nullptr) {
        Node* currentNode = removeFromList(front, rear);
        cout << currentNode->iPayload << " ";

        if (currentNode->ptrLeft != nullptr) {
            addToList(front, rear, currentNode->ptrLeft);
        }

        if (currentNode->ptrRight != nullptr) {
            addToList(front, rear, currentNode->ptrRight);
        }
    }
}