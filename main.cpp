#include <iostream>
#include <chrono>
#include "doubly_linkedlist.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "countingSort.h"
#include "tree.h"

using namespace std;
using namespace dll;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void testFunction(string, void (*)(Node<int>**));
void testOptimizedBubbleSort();
void testsSort();
void testsTree();

int main()
{
    testsSort();
    testsTree();

    return 0;
}

void testFunction(string function_name, void (*func)(Node<int>**))
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node<int>* current_head = nullptr;

    cout << function_name << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        current_head = createRandomList(10000);
        timeStart = high_resolution_clock::now();
        func(&current_head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}

void testOptimizedBubbleSort()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node<int>* current_head = nullptr;

    cout << "Optimized Bubble" << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        current_head = createRandomList(10000);
        timeStart = high_resolution_clock::now();
        optimizedBubbleSort(&current_head, 10000);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}

void testsSort()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    cout << "Metodo";

    for(int i = 0; i < 100; i++)
    {
        cout << "," << i+1;
    }
    cout << "," << "Media" << endl;

    testFunction("Bubble", &bubbleSort);
    testOptimizedBubbleSort();
    testFunction("Selection", &selectionSort);
    testFunction("Optimized Selection", &optimizedSelectionSort);
    testFunction("Insertion", &insertSort);
    testFunction("Counting", &countingSort);
}

void testsTree(string function_name, void (*func)(Node<int>**))
{
    tree::Node<int>* root = nullptr;
    
    root = tree::createRandomTree(100);
    
    std::cout << "BFS Traversal: ";
    tree::bfsTraversal(root);
    cout << endl;
    
    cout << "Tree Height: " << tree::treeHeight(root) << endl;

    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    tree::Node<int>* root = nullptr;

    cout << function_name << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        root = tree::createRandomTree(10000);;
        timeStart = high_resolution_clock::now();
        tree::bfsTraversal(root);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}