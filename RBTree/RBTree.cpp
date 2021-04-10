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

RBNode *RBTree::getSibling(RBNode *node)
{
    if (node->parent == nullptr)
    {
        return nullptr;
    }

    if (node == node->parent->leftChild)
    {
        return node->parent->rightChild;
    }
    return node->parent->leftChild;
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
    cout << "Found " << temp->data << " in the tree bro\n";
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

RBNode *getSibling(RBNode *node)
{
    if (node->parent == nullptr)
        return nullptr;

    if (node == node->parent->leftChild)
        return node->parent->rightChild;
    return node->parent->leftChild;
}

// deletes the given node
void RBTree::deleteElement(RBNode *deletingNode)
{
    RBNode *u;
    if (deletingNode->leftChild != nullptr and deletingNode->rightChild != nullptr)
        u = findSuccessor(deletingNode->rightChild);

    // when leaf
    if (deletingNode->leftChild == nullptr and deletingNode->rightChild == nullptr)
        u = nullptr;

    // when single child
    if (deletingNode->leftChild != nullptr)
        u = deletingNode->leftChild;
    else
        u = deletingNode->rightChild;

    // True when u and deletingNode are both black
    bool uvBlack = ((u == nullptr or u->color == BLACK) and (deletingNode->color == BLACK));
    RBNode *parent = deletingNode->parent;

    if (u == nullptr)
    {
        // u is nullptr therefore deletingNode is leaf
        if (deletingNode == root)
        {
            // deletingNode is root, making root null
            root = nullptr;
        }
        else
        {
            if (uvBlack)
            {
                // u and deletingNode both black
                // deletingNode is leaf, fix double black at deletingNode
                fixDoubleBlack(deletingNode);
            }
            else
            {
                // u or deletingNode is red
                if (getSibling(deletingNode) != nullptr)
                    // sibling is not null, make it red"
                    getSibling(deletingNode)->color = RED;
            }

            // delete deletingNode from the tree
            if (deletingNode == deletingNode->parent->leftChild)
            {
                parent->leftChild = nullptr;
            }
            else
            {
                parent->rightChild = nullptr;
            }
        }
        delete deletingNode;
        return;
    }

    if (deletingNode->leftChild == nullptr or deletingNode->rightChild == nullptr)
    {
        // deletingNode has 1 child
        if (deletingNode == root)
        {
            // deletingNode is root, assign the value of u to deletingNode, and delete u
            deletingNode->data = u->data;
            deletingNode->leftChild = deletingNode->rightChild = nullptr;
            delete u;
        }
        else
        {
            // Detach deletingNode from tree and move u up
            if (deletingNode == deletingNode->parent->leftChild)
            {
                parent->leftChild = u;
            }
            else
            {
                parent->rightChild = u;
            }
            delete deletingNode;
            u->parent = parent;
            if (uvBlack)
            {
                // u and deletingNode both black, fix double black at u
                fixDoubleBlack(u);
            }
            else
            {
                // u or deletingNode red, color u black
                u->color = BLACK;
            }
        }
        return;
    }

    // deletingNode has 2 children, swap values with successor and recurse
    swap(u->data, deletingNode->data);
    deleteElement(u);
}

void RBTree::fixDoubleBlack(RBNode *x)
{
    if (x == root)
        // Reached root
        return;

    RBNode *sibling = getSibling(x), *parent = x->parent;
    if (sibling == nullptr)
    {
        // No sibiling, double black pushed up
        fixDoubleBlack(parent);
    }
    else
    {
        if (sibling->color == RED)
        {
            // Sibling red
            parent->color = RED;
            sibling->color = BLACK;
            if (sibling == sibling->parent->leftChild)
            {
                // leftChild case
                rightRotation(parent);
            }
            else
            {
                // rightChild case
                leftRotation(parent);
            }
            fixDoubleBlack(x);
        }
        else
        {
            // Sibling black
            if ((sibling->leftChild != nullptr && sibling->leftChild->color == RED) || (sibling->rightChild != nullptr && sibling->rightChild->color == RED))
            {
                // at least 1 red children
                if (sibling->leftChild != nullptr and sibling->leftChild->color == RED)
                {
                    if (sibling == sibling->parent->leftChild)
                    {
                        // leftChild leftChild
                        sibling->leftChild->color = sibling->color;
                        sibling->color = parent->color;
                        rightRotation(parent);
                    }
                    else
                    {
                        // rightChild leftChild
                        sibling->leftChild->color = parent->color;
                        rightRotation(sibling);
                        leftRotation(parent);
                    }
                }
                else
                {
                    if (sibling == sibling->parent->leftChild)
                    {
                        // leftChild rightChild
                        sibling->rightChild->color = parent->color;
                        leftRotation(sibling);
                        rightRotation(parent);
                    }
                    else
                    {
                        // rightChild rightChild
                        sibling->rightChild->color = sibling->color;
                        sibling->color = parent->color;
                        leftRotation(parent);
                    }
                }
                parent->color = BLACK;
            }
            else
            {
                // 2 black children
                sibling->color = RED;
                if (parent->color == BLACK)
                    fixDoubleBlack(parent);
                else
                    parent->color = BLACK;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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