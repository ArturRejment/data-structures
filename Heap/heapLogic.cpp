#include <fstream>
#include <time.h>
#include "heap.cpp"

void deleteHeap(Heap *heap)
{
    Heap newHeap = Heap();
    *heap = newHeap;
}

void fillHeapFromFile(Heap *heap)
{
    fstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "[Heap] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while ((!file.eof()))
    {
        file >> data;
        heap->insert(data);
    }
}

void fillHeapWithRandomData(Heap *heap)
{
    srand(time(NULL));

    if (!heap->isEmpty())
    {
        cout << "Heap is not empty!\n";
        return;
    }

    int size;
    cout << "Enter the size of the heap: " << flush;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        heap->insert(value);
    }
}

void fillHeapForExperiment(Heap *heap, int size, int range)
{
    if (!heap->isEmpty())
    {
        deleteHeap(heap);
    }
    for (int i = 0; i < size; i++)
    {
        int value = rand() % range;
        heap->insert(value);
    }
}

void heapExperiment(Heap *heap)
{
    srand(time(NULL));
    int size, value, testNumber, range;
    float time;

    cout << "Please enter the size of the heap: " << flush;
    cin >> size;

    cout << "Please enter number of tests: " << flush;
    cin >> testNumber;

    cout << "Please enter maximum size of the arguments in structure: " << flush;
    cin >> range;

    //! Insert element
    time = 0;
    for (int i = 0; i < testNumber; i++)
    {
        fillHeapForExperiment(heap, size, range);
        value = rand() % range;
        Timer timer;
        heap->insert(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element to the heap took on average: " << time / testNumber << " ms\n";

    //! Delete element
    time = 0;
    for (int i = 0; i < testNumber; i++)
    {
        fillHeapForExperiment(heap, size, range);
        value = rand() % range;
        Timer timer;
        heap->deleteElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element from the heap took on average: " << time / testNumber << " ms\n";

    //! Find element
    time = 0;
    for (int i = 0; i < testNumber; i++)
    {
        fillHeapForExperiment(heap, size, range);
        value = rand() % range;
        Timer timer;
        heap->findElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Finding element in the heap took on average: " << time / testNumber << " ms\n";
}