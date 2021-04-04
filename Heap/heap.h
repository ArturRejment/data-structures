#include <vector>

class Heap
{
private:
    int size;
    std::vector<int> heap = {-1};

    int parent(int i) { return i >> 1; };           // i/2
    int leftChild(int i) { return i << 1; };        // i*2
    int rightChild(int i) { return (i << 1) + 1; }; // i*2+1

public:
    bool isEmpty();
    int getMax();
    void insert(int value);
    void printHeap();
    void shiftUp(int i);
    void shiftDown(int i);
};