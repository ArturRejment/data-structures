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

void RBTree::fixDoubleBlack(RBNode *node)
{
    if (node == root)
        // Reached root
        return;

    RBNode *sibling = getSibling(node), *parent = node->parent;
    if (sibling == NULL)
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
                // left case
                rightRotation(parent);
            }
            else
            {
                // right case
                leftRotation(parent);
            }
            fixDoubleBlack(node);
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
                        // left left
                        sibling->leftChild->color = sibling->color;
                        sibling->color = parent->color;
                        rightRotation(parent);
                    }
                    else
                    {
                        // right left
                        sibling->leftChild->color = parent->color;
                        rightRotation(sibling);
                        leftRotation(parent);
                    }
                }
                else
                {
                    if (sibling == sibling->parent->leftChild)
                    {
                        // left right
                        sibling->rightChild->color = parent->color;
                        leftRotation(sibling);
                        rightRotation(parent);
                    }
                    else
                    {
                        // right right
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

void RBTree::deleteElement(RBNode *node)
{
    //! Find node that replaces a deleted node
    RBNode *replacingNode;
    // When node have 2 children
    if (node->leftChild != nullptr && node->rightChild != nullptr)
        replacingNode = findSuccessor(node->rightChild);
    // When node is a leaf
    else if (node->leftChild == nullptr && node->rightChild == nullptr)
        replacingNode = nullptr;
    // When node has one child
    if (node->leftChild != nullptr)
        replacingNode = node->leftChild;
    else
        replacingNode = node->rightChild;

    RBNode *parent = node->parent;

    if (replacingNode == nullptr)
    {
        // replacingNode is nullptr therefore node is leaf
        if (node == root)
        {
            // node is root, making root null
            root = nullptr;
        }
        else
        {
            if ((replacingNode == nullptr or replacingNode->color == BLACK) and (node->color == BLACK))
            {
                // replacingNode and node both black
                // node is leaf, fix double black at node
                fixDoubleBlack(node);
            }
            else
            {
                // replacingNode or node is red
                if (getSibling(node) != nullptr)
                    // sibling is not null, make it red"
                    getSibling(node)->color = RED;
            }

            // delete node from the tree
            if (node == node->parent->leftChild)
            {
                parent->leftChild = nullptr;
            }
            else
            {
                parent->rightChild = nullptr;
            }
        }
        delete node;
        return;
    }

    if (node->leftChild == nullptr or node->rightChild == nullptr)
    {
        // node has 1 child
        if (node == root)
        {
            // node is root, assign the value of replacingNode to node, and delete replacingNode
            node->data = replacingNode->data;
            node->leftChild = node->rightChild = nullptr;
            delete replacingNode;
        }
        else
        {
            // Detach node from tree and move replacingNode up
            if (node == node->parent->leftChild)
            {
                parent->leftChild = replacingNode;
            }
            else
            {
                parent->rightChild = replacingNode;
            }
            delete node;
            replacingNode->parent = parent;
            if ((replacingNode == nullptr or replacingNode->color == BLACK) and (node->color == BLACK))
            {
                // replacingNode and node both black, fix double black at replacingNode
                fixDoubleBlack(replacingNode);
            }
            else
            {
                // replacingNode or node red, color replacingNode black
                replacingNode->color = BLACK;
            }
        }
        return;
    }
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