#include <iostream>
#include "RBTree.h"
using namespace std;

RBTree ::RBTree()
{
    root = nullptr;
}

RBNode *RBTree::getRoot()
{
    return this->root;
}

void RBTree ::deleteTree(RBNode *node)
{
    if (node != nullptr)
    {
        deleteTree(node->rightChild);
        deleteTree(node->leftChild);
        delete node;
    }
}

bool RBTree::isEmpty()
{
    if (root == nullptr)
        return true;
    return false;
}

RBNode *RBTree::find(int value)
{
    RBNode *temp;

    temp = root;
    while ((temp != nullptr) && (temp->data != value))
    {
        if (value < temp->data)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    if (temp == nullptr)
        return nullptr;
    return temp;
}

RBNode *RBTree::findMin(RBNode *nodeToFind)
{
    if (nodeToFind != nullptr)
    {
        while (nodeToFind->leftChild != nullptr)
        {
            nodeToFind = nodeToFind->leftChild;
        }
    }
    return nodeToFind;
}

RBNode *RBTree::findSuccessor(RBNode *node)
{
    RBNode *temp;

    if (node != nullptr)
    {
        if (node->rightChild != nullptr)
        {
            return findMin(node->rightChild);
        }
        else
        {
            temp = node->parent;
            while ((temp != nullptr) && (node == temp->rightChild))
            {
                node = temp;
                temp = temp->parent;
            }
            return temp;
        }
    }
    return nullptr;
}

void RBTree::leftRotation(RBNode *rotatingNode)
{
    RBNode *rightChildOfRotatingNode = rotatingNode->rightChild, *tempParent = rotatingNode->parent;

    if (rightChildOfRotatingNode)
    {
        rotatingNode->rightChild = rightChildOfRotatingNode->leftChild;
        if (rotatingNode->rightChild)
            rotatingNode->rightChild->parent = rotatingNode;

        rightChildOfRotatingNode->leftChild = rotatingNode;
        rightChildOfRotatingNode->parent = tempParent;
        rotatingNode->parent = rightChildOfRotatingNode;

        if (tempParent)
        {
            if (tempParent->leftChild == rotatingNode)
                tempParent->leftChild = rightChildOfRotatingNode;
            else
                tempParent->rightChild = rightChildOfRotatingNode;
        }
        else
            root = rightChildOfRotatingNode;
    }

    // RBNode *right = rotatingNode->rightChild;
    // rotatingNode->rightChild = right->leftChild;

    // if (rotatingNode->rightChild != nullptr)
    // {
    //     rotatingNode->rightChild->parent = rotatingNode;
    // }
    // right->parent = rotatingNode->parent;
    // if (rotatingNode->parent == nullptr)
    //     root = right;
    // else if (rotatingNode == rotatingNode->parent->leftChild)
    //     rotatingNode->parent->leftChild = right;
    // else
    //     rotatingNode->parent->rightChild = right;

    // right->leftChild = rotatingNode;
    // rotatingNode->parent = right;

    // RBNode *B, *p;

    // B = A->rightChild;
    // if (B != nullptr)
    // {
    //     p = A->parent;
    //     A->rightChild = B->leftChild;
    //     if (A->rightChild != nullptr)
    //         A->rightChild->parent = A;

    //     B->leftChild = A;
    //     B->parent = p;
    //     A->parent = B;

    //     if (p != nullptr)
    //     {
    //         if (p->leftChild == A)
    //             p->leftChild = B;
    //         else
    //             p->rightChild = B;
    //     }
    //     else
    //         root = B;
    // }
}

void RBTree::rightRotation(RBNode *rotatingNode)
{
    RBNode *leftOfRotatingNode = rotatingNode->leftChild, *tempParent = rotatingNode->parent;

    if (leftOfRotatingNode)
    {
        rotatingNode->leftChild = leftOfRotatingNode->rightChild;
        if (rotatingNode->leftChild)
            rotatingNode->leftChild->parent = rotatingNode;

        leftOfRotatingNode->rightChild = rotatingNode;
        leftOfRotatingNode->parent = tempParent;
        rotatingNode->parent = leftOfRotatingNode;

        if (tempParent)
        {
            if (tempParent->leftChild == rotatingNode)
                tempParent->leftChild = leftOfRotatingNode;
            else
                tempParent->rightChild = leftOfRotatingNode;
        }
        else
            root = leftOfRotatingNode;
    }

    // RBNode *left = rotatingNode->leftChild;
    // rotatingNode->leftChild = left->rightChild;

    // if (rotatingNode->leftChild == nullptr)
    //     rotatingNode->leftChild->parent = rotatingNode;

    // left->parent = rotatingNode->parent;

    // if (rotatingNode->parent == nullptr)
    //     root = left;
    // else if (rotatingNode == rotatingNode->parent->leftChild)
    //     rotatingNode->parent->leftChild = left;
    // else
    //     rotatingNode->parent->rightChild = left;

    // left->rightChild = rotatingNode;
    // rotatingNode->parent = left;

    // RBNode *B, *p;

    // B = A->leftChild;
    // if (B != nullptr)
    // {
    //     p = A->parent;
    //     A->leftChild = B->rightChild;
    //     if (A->leftChild != nullptr)
    //         A->leftChild->parent = A;

    //     B->rightChild = A;
    //     B->parent = p;
    //     A->parent = B;

    //     if (p != nullptr)
    //     {
    //         if (p->leftChild == A)
    //             p->leftChild = B;
    //         else
    //             p->rightChild = B;
    //     }
    //     else
    //         root = B;
    // }
}

void RBTree::deleteElement(RBNode *nodeToDelete)
{
    RBNode *temp1, *temp2, *temp3;

    if ((nodeToDelete->leftChild == nullptr) || (nodeToDelete->rightChild == nullptr))
        temp2 = nodeToDelete;
    else
        temp2 = findSuccessor(nodeToDelete);

    if (temp2->leftChild != nullptr)
        temp3 = temp2->leftChild;
    else
        temp3 = temp2->rightChild;

    temp3->parent = temp2->parent;

    if (temp2->parent == nullptr)
        root = temp3;
    else if (temp2 == temp2->parent->leftChild)
        temp2->parent->leftChild = temp3;
    else
        temp2->parent->rightChild = temp3;

    if (temp2 != nodeToDelete)
        nodeToDelete->data = temp2->data;

    if (temp2->color == BLACK) // Naprawa struktury drzewa czerwono-czarnego
        while ((temp3 != root) && (temp3->color == BLACK))
            if (temp3 == temp3->parent->leftChild)
            {
                temp1 = temp3->parent->rightChild;

                if (temp1->color == RED)
                { // Przypadek 1
                    temp1->color = BLACK;
                    temp3->parent->color = RED;
                    leftRotation(temp3->parent);
                    temp1 = temp3->parent->rightChild;
                }

                if ((temp1->leftChild->color == BLACK) && (temp1->rightChild->color == BLACK))
                { // Przypadek 2
                    temp1->color = RED;
                    temp3 = temp3->parent;
                    continue;
                }

                if (temp1->rightChild->color == BLACK)
                { // Przypadek 3
                    temp1->leftChild->color = BLACK;
                    temp1->color = RED;
                    rightRotation(temp1);
                    temp1 = temp3->parent->rightChild;
                }

                temp1->color = temp3->parent->color; // Przypadek 4
                temp3->parent->color = BLACK;
                temp1->rightChild->color = BLACK;
                leftRotation(temp3->parent);
                temp3 = root; // To spowoduje zakończenie pętli
            }
            else
            { // Przypadki lustrzane
                temp1 = temp3->parent->leftChild;

                if (temp1->color == RED)
                { // Przypadek 1
                    temp1->color = BLACK;
                    temp3->parent->color = RED;
                    rightRotation(temp3->parent);
                    temp1 = temp3->parent->leftChild;
                }

                if ((temp1->leftChild->color == BLACK) && (temp1->rightChild->color == BLACK))
                { // Przypadek 2
                    temp1->color = RED;
                    temp3 = temp3->parent;
                    continue;
                }

                if (temp1->leftChild->color == BLACK)
                { // Przypadek 3
                    temp1->rightChild->color = BLACK;
                    temp1->color = RED;
                    leftRotation(temp1);
                    temp1 = temp3->parent->leftChild;
                }

                temp1->color = temp3->parent->color; // Przypadek 4
                temp3->parent->color = BLACK;
                temp1->leftChild->color = BLACK;
                rightRotation(temp3->parent);
                temp3 = root; // To spowoduje zakończenie pętli
            }

    temp3->color = BLACK;

    delete temp2;
}

// void RBTree::insertElement(int value)
// {
//     RBNode *newNode, *uncle;

//     newNode = new RBNode(value);
//     newNode->parent = root;

//     if (newNode->parent == nullptr)
//         root = newNode;

//     else

//         while (true)
//         {
//             if (value < newNode->parent->data)
//             {
//                 if (newNode->parent->leftChild == nullptr)
//                 {
//                     newNode->parent->leftChild = newNode;
//                     break;
//                 }
//                 newNode->parent = newNode->parent->leftChild;
//             }
//             else
//             {
//                 if (newNode->parent->rightChild == nullptr)
//                 {
//                     newNode->parent->rightChild = newNode;
//                     break;
//                 }
//                 newNode->parent = newNode->parent->rightChild;
//             }
//         }

//     newNode->color = RED;
//     while ((newNode != root) && (newNode->parent->color == RED))
//     {
//         if (newNode->parent == newNode->parent->parent->leftChild)
//         {
//             uncle = newNode->parent->parent->rightChild;

//             if (uncle->color == RED) // First case
//             {
//                 newNode->parent->color = BLACK;
//                 uncle->color = BLACK;
//                 newNode->parent->parent->color = RED;
//                 newNode = newNode->parent->parent;
//                 continue;
//             }

//             if (newNode == newNode->parent->rightChild) // Second case
//             {
//                 newNode = newNode->parent;
//                 leftRotation(newNode);
//             }

//             newNode->parent->color = BLACK; // Third case
//             newNode->parent->parent->color = RED;
//             rightRotation(newNode->parent->parent);
//             break;
//         }
//         else // Mirror cases
//         {
//             uncle = newNode->parent->parent->leftChild;

//             if (uncle->color == RED)
//             {
//                 newNode->parent->color = BLACK;
//                 uncle->color = BLACK;
//                 newNode->parent->parent->color = RED;
//                 newNode = newNode->parent->parent;
//                 continue;
//             }

//             if (newNode == newNode->parent->leftChild)
//             {
//                 newNode = newNode->parent;
//                 rightRotation(newNode);
//             }

//             newNode->parent->color = BLACK;
//             newNode->parent->parent->color = RED;
//             leftRotation(newNode->parent->parent);
//             break;
//         }
//     }
//     root->color = BLACK;
// }

void RBTree::insertElement(int value)
{
    RBNode *newNode = new RBNode(value);

    root = insertElementNormalBST(root, newNode);

    restoreRBTreeProperties(newNode);
}

RBNode *RBTree::insertElementNormalBST(RBNode *rootB, RBNode *newNode)
{
    if (rootB == nullptr)
        return newNode;

    if (newNode->data <= rootB->data)
    {
        rootB->leftChild = insertElementNormalBST(rootB->leftChild, newNode);
        rootB->leftChild->parent = rootB;
    }
    else if (newNode->data > rootB->data)
    {
        rootB->rightChild = insertElementNormalBST(rootB->rightChild, newNode);
        rootB->rightChild->parent = rootB;
    }
    return rootB;
}

void RBTree::restoreRBTreeProperties(RBNode *&newNode)
{
    RBNode *parent = nullptr;
    RBNode *grand_parent = nullptr;
    RBNode *uncle = nullptr;

    while ((newNode != root) && (newNode->color != BLACK) && (newNode->parent->color == RED))
    {
        parent = newNode->parent;
        grand_parent = newNode->parent->parent;

        if (parent == grand_parent->leftChild)
        {
            uncle = grand_parent->rightChild;

            if (uncle != nullptr && uncle->color == RED)
            {
                grand_parent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grand_parent;
            }

            else
            {
                if (newNode == parent->rightChild)
                {
                    leftRotation(parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                rightRotation(grand_parent);
                swap(parent->color, grand_parent->color);
                newNode = parent;
            }
        }

        else
        {
            uncle = grand_parent->leftChild;

            if ((uncle != nullptr) && uncle->color == RED)
            {
                grand_parent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grand_parent;
            }

            else
            {
                if (newNode == parent->leftChild)
                {
                    rightRotation(parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                leftRotation(grand_parent);
                swap(parent->color, grand_parent->color);
                newNode = parent;
            }
        }
    }
    root->color = BLACK;
}

void inorderH(RBNode *root)
{
    if (root == nullptr)
        return;

    inorderH(root->leftChild);
    cout << root->data << " ";
    inorderH(root->rightChild);
}

void RBTree::inorder()
{
    inorderH(root);
}