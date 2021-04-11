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

void fillTreeForExperiment(RBTree *tree, int size)
{
    int value;
    if (!tree->isEmpty())
    {
        deleteTree(tree);
    }

    for (int i = 0; i < size; i++)
    {
        value = rand() % 100000;
        tree->insertElement(value);
    }
}

void treeExperiment(RBTree *tree)
{
    srand(time(NULL));
    int size, value;
    float time;

    cout << "Please enter the size of the red-black tree: " << flush;
    cin >> size;

    //! Insert element
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillTreeForExperiment(tree, size);
        value = rand() % 100000;
        Timer timer;
        tree->insertElement(value);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Inserting element to the red-black tree took on average: " << time / 100 << " ms\n";

    //! Delete element
    RBNode *node;
    time = 0;
    for (int i = 0; i < 100; i++)
    {
        fillTreeForExperiment(tree, size);
        value = rand() % 100000;
        node = tree->find(value);
        Timer timer;
        tree->deleteElement(node);
        time += timer.getTime().count() * 1000.0f;
    }
    cout << "Deleting element form the red-black tree took on average: " << time / 100 << " ms\n";
}