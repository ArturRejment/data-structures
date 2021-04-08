#include <fstream>
#include <time.h>
#include "RBTree.cpp"

void deleteTree(RBTree *tree)
{
    tree->deleteTree(tree->getRoot());
}

void fillTreeFromFile(RBTree *tree)
{
    fstream file;
    file.open("data.txt", ios::in);

    if (!file.is_open())
    {
        cout << "[Red-Black Tree] Cannot open data.txt\n";
        return;
    }

    int size;
    int data;
    file >> size;

    while ((!file.eof()))
    {
        file >> data;
        tree->insertElement(data);
    }
}

void fillTreeWithRandomData(RBTree *tree)
{
    srand(time(NULL));

    if (!tree->isEmpty())
    {
        cout << "Red-Black Tree is not empty!\n";
        return;
    }

    int size;
    cout << "Enter the size of the tree: " << flush;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value = rand() % 300;
        tree->insertElement(value);
    }
}