#include "tree.h"

namespace tree
{
    tree::Node<int>* createRandomTree(int iLength, int start, int stop)
    {
        tree::Node<int>* root = tree::createNode((rand()%(stop-start))+start);

        for(int i = 1; i < iLength; i++)
        {
            tree:insertNode(root, (rand()%(stop-start))+start);
        }

        return root;
    }
}