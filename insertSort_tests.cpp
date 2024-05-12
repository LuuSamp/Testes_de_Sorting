#include <iostream>
#include <chrono>
#include "doubly_linkedlist.h"
#include "insertSort.h"

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main()
{
    int mean = 0;
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    Node* current_head = nullptr;
    for(int i = 0; i < 100; i++)
    {
        current_head = createRandomList(10000);
        timeStart = high_resolution_clock::now();
        insertSort(&current_head);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Tempo utilizado na lista " << i+1 << ": " << timeDuration.count() << endl;

        mean += timeDuration.count()/100;
    }
    cout << endl;

    cout << "Media: " << mean << endl;

}