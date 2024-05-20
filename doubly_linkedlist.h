typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void deleteNode(Node**, Node*);
void displayList(Node*);
Node* createRandomList(int);
void swapPayload(Node*, Node*); 
int maxValue(Node*);