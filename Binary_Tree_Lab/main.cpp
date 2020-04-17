/*
 Carter Fluckiger
 Data Structure Spring 2020
 Due: April 17, 2020
 Lab: Create a binary tree class which will take strings of website names and sort them in alphabetical order. Your class should also be able to sort them in reverse alphabetical order as well.
*/

#include <iostream>
#include "Binary_Tree.h"

int main()
{
    BiTree Tree;
    Tree.AddItem(5);
    Tree.AddItem(6);
    Tree.AddItem( 3 );
    Tree.AddItem(99);
    Tree.AddItem(1);
    Tree.DeleteItem(5);
  
    Tree.PrintTree();
    
    return 0;
}
