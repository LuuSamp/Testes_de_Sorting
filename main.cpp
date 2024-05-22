#include <iostream>
#include <chrono>
#include "doubly_linkedlist.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "countingSort.h"

using std::cout;
using std::endl;
using std::string;

using namespace auxListFuncs;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void testFunction(string, void (*)(Node**));
void testOptimizedBubbleSort();

int main()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node* current_head = nullptr;

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

    return 0;
}

void testFunction(string function_name, void (*func)(Node**))
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node* current_head = nullptr;

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

    Node* current_head = nullptr;

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