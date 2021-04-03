#include <iostream>
#include <conio.h>
using namespace std;

void printDefaultMenu()
{
    cout << "[1] Add element" << endl;
    cout << "[2] Delete element" << endl;
    cout << "[3] Find element" << endl;
    cout << "[4] Return" << endl;
}

void arrayMenu()
{
    cout << "------------- ARRAY MENU -------------" << endl;
    printDefaultMenu();

    char choice = getch();

    switch (choice)
    {
    case '4':
        return;
        break;

    default:
        break;
    }
}

void listMenu()
{
    cout << "------------- LINKED LIST MENU -------------" << endl;
    printDefaultMenu();

    char choice = getch();

    switch (choice)
    {
    case '4':
        return;
        break;

    default:
        break;
    }
}

void heapMenu()
{
    cout << "------------- BINARY HEAP MENU -------------" << endl;
    printDefaultMenu();

    char choice = getch();

    switch (choice)
    {
    case '4':
        return;
        break;

    default:
        break;
    }
}

void treeMenu()
{
    cout << "------------- RED-BLACK TREE MENU -------------" << endl;
    printDefaultMenu();

    char choice = getch();

    switch (choice)
    {
    case '4':
        return;
        break;

    default:
        break;
    }
}

void printMenu()
{
    do
    {
        char choice;

        cout << "------------- MENU -------------" << endl;
        cout << "[1] Array" << endl;
        cout << "[2] Linked list" << endl;
        cout << "[3] Binary heap" << endl;
        cout << "[4] Red-black tree" << endl;
        cout << "[5] Exit program" << endl;

        choice = getch();
        switch (choice)
        {
        case '1':
            arrayMenu();
            break;
        case '2':
            listMenu();
            break;
        case '3':
            heapMenu();
            break;
        case '4':
            treeMenu();
            break;
        case '5':
            return;
            break;
        default:
            return;
            break;
        }
    } while (true);
}