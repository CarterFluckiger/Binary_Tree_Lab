#include "Binary_Tree.h"
#include <stdio.h>
#include <iostream>
#include <queue>

//I don't like to use namespace but xcode was being weird
using namespace std;

//Struct for each node to have info and a right and left pointer
struct Nodetype
{
    Itemtype info;
    Nodetype* right;
    Nodetype* left;
};

//Constructor
BiTree::BiTree()
{
    root = nullptr;
}
//Destructor
BiTree::~BiTree()
{
    MakeEmpty();
}
//Adds item
void BiTree:: AddItem(Itemtype item)
{
    //Calls insert in private of class
    Insert(root , item);
}

void BiTree:: ResetTree()
{
    MakeEmpty();
}

void BiTree:: MakeEmpty()
{
    root = nullptr;
}

//Tries to add the item with a try catch to find if its full
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
//Checks if its empty
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

void BiTree::DeleteNode(Nodetype* &node)
{
Nodetype* temp = node;
Nodetype* parent = nullptr;
    //Finds whether the node has right or left information and deletes the node properly keeping the tree intact
    if (node->left == nullptr && node->right == nullptr)
    {
        node = nullptr;
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
        //I added an x int and a if statement for a specific error that I ran into
        //It fixes the problem of when the node being deleted doesn't enter the while loop because it has no left pointer values
        temp = node->right;
        int x=0;
        while (temp->left != nullptr)
        {
            x++;
        parent = temp;
        temp = temp->left;
        }
        if(x == 0)
        {
            node = temp;
        }
        else
        {
        parent->left = temp->right;
        node->info = temp->info;
        delete temp;
        }
    }
}

void BiTree::Insert(Nodetype* &node, Itemtype item)
{
    //If it is not equal to nullptr it uses recursion until it finds the correct place to insert
    if( node == nullptr)
    {
        node = new Nodetype;
        node->left = nullptr;
        node->right = nullptr;
        node->info = item;
    }
        else if( item < node->info )
        {
            //Recursion to the left
            Insert( node->left, item );
        }
        else
        {
            //Recursion to the right
            Insert( node->right , item );
        }
}

//Finds the correct place to delete then calls Deletenode to keep the Tree intact
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
        //Only run when item is found and calls to Delete node
        DeleteNode(node);
    }
}
//Used to call private function to print
void BiTree::PrintFTree()
{
    PrivatePrintFTree( root );
}

//Prints forward numeric order
void BiTree::PrivatePrintFTree( Nodetype* &node)
{
    //Recursion calls
    if( root != nullptr )
    {
        if(node->left != nullptr)
        {
            PrivatePrintFTree(node->left);
        }
        cout<<node->info<<" ";
        if(node->right != nullptr)
        {
            PrivatePrintFTree(node->right);
        }
        
    }
    else
    {
        cout<<"The tree has no values :( . . . you made the tree sad"<<endl;
    }
}

//Used to call private delete function
void BiTree::DeleteItem(Itemtype item)
{
        Delete(root, item);
}
//Calls private reverse print private function
void BiTree::PrintRTree()
{
    PrivateRPrint(root);
}
//Same as normal print function but the opposite. . . literally the funniest and easiest after doing forward version
void BiTree::PrivateRPrint(Nodetype *&node)
{
    //Uses some recursion again. . . it's just so easy to fall into the bliss of recursion ease
    if( root != nullptr )
       {
           if(node->right != nullptr)
           {
               PrivateRPrint(node->right);
           }
           cout<<node->info<<" ";
           if(node->left != nullptr)
           {
               PrivateRPrint(node->left);
           }
           
       }
       else
       {
           cout<<"The tree has no values :( . . . you made the tree sad"<<endl;
       }
}
// Calls private Tree output of tree
void BiTree::PrintTree()
{
    PrivateTPrint(root);
}

//Outputs tree to the screen in tree format
void BiTree::PrivateTPrint(Nodetype *&node)
{
    //Level variable for the output
    int level = 0;
    //using queue library for a few of these functions
    queue<Nodetype*> q;
    q.push(root);

    while(true)
    {
        // I am getting a yellow pop up but it works the way it should
        int length = q.size();
        if( length == 0 )
        {
            break;
        }
        int i = 0;
        cout<<"Level "<<level<<": ";
        level++;
        //Uses a lot of queue library simple functions like push and pop to put the numbers on the same level in a queue and work through the list
       while(i<length)
       {
                      Nodetype* n = q.front();
            cout<<n->info<<" ";
// if statement for moving through the items in the queue to output to the screen correctly
            if(n->left != nullptr)
            {
              q.push(n->left);
            }
                if(n->right != nullptr)
            {
              q.push(n->right);
            }
            q.pop();
            i++;
           }
           cout<<endl;
         }
    }
