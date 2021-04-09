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

void RBTree::deleteElement(int value)
{
    root = deleteElementLikeBST(root, value);
    restoreRBTreeProperties(root);
}

RBNode *RBTree::deleteElementLikeBST(RBNode *node, int value)
{
    if (node == nullptr)
        return node;

    if (value < node->data)
        node->leftChild = deleteElementLikeBST(node->leftChild, value);

    else if (value > node->data)
    {
        node->rightChild = deleteElementLikeBST(node->rightChild, value);
    }
    else
    {
        if (node->leftChild == nullptr)
        {
            RBNode *temp = node->leftChild;
            free(node);
            return temp;
        }
        else if (node->rightChild == nullptr)
        {
            RBNode *temp = node->leftChild;
            free(node);
            return temp;
        }

        RBNode *temp = findMin(node->rightChild);
        node->data = temp->data;
        node->rightChild = deleteElementLikeBST(node->rightChild, temp->data);
    }
    return node;
}

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