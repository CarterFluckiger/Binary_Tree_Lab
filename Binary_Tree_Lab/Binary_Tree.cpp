#include "Binary_Tree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct Nodetype
{
    Itemtype info;
    Nodetype* right;
    Nodetype* left;
};


BiTree::BiTree()
{
    root = nullptr;
}

BiTree::~BiTree()
{
    MakeEmpty();
}

void BiTree:: AddItem(Itemtype item)
{
    Insert(root , item);
}

void BiTree:: ResetTree()
{
    MakeEmpty();
}

Itemtype BiTree::GetItem()
{
    return Itemtype();
}


void BiTree:: MakeEmpty()
{
    root = nullptr;
    length = 0;
}

bool BiTree:: IsFull()
{
    try
    {
        Nodetype* temp = new Nodetype;
        delete temp;
        return false;
        
    } catch (std::bad_alloc e)
    {
        return true;
    }
}

bool BiTree:: IsEmpty()
{
    if(root != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BiTree:: PutItem(Itemtype item)
{
    Insert(root,  item);
}

void BiTree::DeleteNode(Nodetype* &node)
{
    Nodetype* temp = node;
    Nodetype* parent = nullptr;
    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
    }
    else if (node->left != nullptr && node->right == nullptr)
    {
        node->info = node->left->info;
        temp = node->left;
        node->right = node->left->right;
        node->left = node->left->left;
        delete temp;
    }
    else if (node->left == nullptr && node->right != nullptr)
    {
        node->info = node->right->info;
        temp = node->right;
        node->left = node->right->left;
        node->right = node->right->right;
        delete temp;
    }
    else
    {
        temp = node->right;
        while (temp->left != nullptr)
        {
            parent = temp;
            temp = temp->left;
        }
        parent->left = temp->right;
        node->info = temp->info;
        delete temp;
    }
}

void BiTree::Insert(Nodetype* &node, Itemtype item)
{
    if( node == nullptr)
    {
        node = new Nodetype;
        node->left = nullptr;
        node->right = nullptr;
        node->info = item;
    }
        else if( item < node->info )
        {
            Insert( node->left, item );
        }
        else
        {
            Insert( node->right , item );
        }
}

void BiTree::Delete(Nodetype * &node,Itemtype item)
{
    if (item < node->info)
    {
        Delete(node->left, item);
    }
    else if (item > node->info)
    {
        Delete(node->right, item);
    }
    else
    {
        DeleteNode(node);
    }
}

void BiTree::PrintTree()
{
    PrivatePrintTree( root );
}

void BiTree::PrivatePrintTree( Nodetype* &node)
{
    if( root != nullptr )
    {
        if(node->left != nullptr)
        {
            PrivatePrintTree(node->left);
        }
        cout<<node->info<<" ";
        if(node->right != nullptr)
        {
            PrivatePrintTree(node->right);
        }
        
    }
    else
    {
        cout<<"The tree has no values :( . . . you made the tree sad"<<endl;
    }
}

void BiTree::DeleteItem(Itemtype item)
{
        Delete(root, item);
}
