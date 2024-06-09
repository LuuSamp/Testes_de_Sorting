#include "tree.h"

namespace tree
{
    tree::Node<int>* createRandomTree(int iLength)
    {
        tree::Node<int>* root = tree::createNode((rand()%100)+1);

        for(int i = 1; i < iLength; i++)
        {
            tree:insertNode(root, (rand()%100)+1);
        }

        return root;
    }
}