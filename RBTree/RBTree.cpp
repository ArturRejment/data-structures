#include <iostream>
#include "RBTree.h"
using namespace std;

RBTree ::RBTree()
{
    root = nullptr;
}

RBTree ::~RBTree()
{
    deleteTree(root);
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
}

void RBTree::insertElement(int value)
{
    RBNode *newNode, *uncle;

    newNode = new RBNode(value);

    if (newNode->parent == nullptr)
        root = newNode;

    else
    {
        while (true)
        {
            if (value < newNode->parent->data)
            {
                if (newNode->parent->leftChild == nullptr)
                {
                    newNode->parent->leftChild = newNode;
                    break;
                }
                newNode->parent = newNode->parent->leftChild;
            }
            else
            {
                if (newNode->parent->rightChild == nullptr)
                {
                    newNode->parent->rightChild = newNode;
                    break;
                }
                newNode->parent = newNode->parent->rightChild;
            }
        }

        newNode->color = true;
        while ((newNode != root) && (newNode->parent->color == true))
        {
            if (newNode->parent == newNode->parent->parent->leftChild)
            {
                uncle = newNode->parent->parent->rightChild;

                if (uncle->color == true) // First case
                {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode->parent->parent->color = BLACK;
                    newNode = newNode->parent->parent;
                    continue;
                }

                if (newNode == newNode->parent->rightChild) // Second case
                {
                    newNode = newNode->parent;
                    leftRotation(newNode);
                }

                newNode->parent->color = BLACK; // Third case
                newNode->parent->parent->color = RED;
                rightRotation(newNode->parent->parent);
                break;
            }
            else // Mirror cases
            {
                uncle = newNode->parent->parent->leftChild;

                if (uncle->color == true)
                {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode->parent->parent->color = RED;
                    newNode = newNode->parent->parent;
                    continue;
                }

                if (newNode == newNode->parent->leftChild)
                {
                    newNode = newNode->parent;
                    rightRotation(newNode);
                }

                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotation(newNode->parent->parent);
                break;
            }
        }
        root->color = BLACK;
    }
}