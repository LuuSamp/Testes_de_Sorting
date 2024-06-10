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

void testFunctionSort(string, void (*)(Node<int>**));
void testOptimizedBubbleSort();
void testsSort();
void testBfs();
void testDfs();
void testsTree();
void testCreateList();
void testCreateTree();

int main()
{
    cout << "Metodo";

    for(int i = 0; i < 100; i++)
    {
        cout << "," << i+1;
    }
    cout << "," << "Media" << endl;

    //testsSort();
    //testsTree();
    testCreateList();
    testCreateTree();

    return 0;
}

void testFunctionSort(string function_name, void (*func)(Node<int>**))
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
        current_head = createRandomList(10000, 1, 1000);
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
        current_head = createRandomList(10000, 1, 1000);
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
    testFunctionSort("Bubble", &bubbleSort);
    testOptimizedBubbleSort();
    testFunctionSort("Selection", &selectionSort);
    testFunctionSort("Optimized Selection", &optimizedSelectionSort);
    testFunctionSort("Insertion", &insertSort);
    testFunctionSort("Counting", &countingSort);
}

void testBfs()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    tree::Node<int>* root = nullptr;

    cout << "BFS Traversal" << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        root = tree::createRandomTree(10000, 1, 1000);
        timeStart = high_resolution_clock::now();
        tree::bfsSearch(root, 0);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}

void testDfs()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    tree::Node<int>* root = nullptr;

    cout << "DFS Traversal" << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        root = tree::createRandomTree(10000, 1, 1000);
        timeStart = high_resolution_clock::now();
        tree::dfsSearch(root, 0);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}

void testsTree()
{
    testBfs();
    testDfs();
}

void testCreateList()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node<int>* current_head = nullptr;

    cout << "Create List" << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        timeStart = high_resolution_clock::now();
        current_head = createRandomList(10000, 1, 1000);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}

void testCreateTree()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    tree::Node<int>* current_head = nullptr;

    cout << "Create Tree" << ",";
    for(int i = 0; i < 100; i++)
    {
        srand(i);
        timeStart = high_resolution_clock::now();
        current_head = tree::createRandomTree(10000, 1, 1000);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << timeDuration.count() << ",";

        mean += timeDuration.count()/100;
    }

    cout << mean << endl;
}
