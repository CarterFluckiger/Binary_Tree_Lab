/*
 Carter Fluckiger
 Data Structure Spring 2020
 Due: April 17, 2020
 Lab: Create a binary tree class which will take strings of website names and sort them in alphabetical order. Your class should also be able to sort them in reverse alphabetical order as well.
*/

#include <iostream>
#include "Binary_Tree.h"

using namespace std;


int main()
{
    //Have some stuff in the main for testing the functions
    BiTree Tree;
    Tree.AddItem( 5 );

    Tree.AddItem( 1 );
    Tree.AddItem( 2 );
    Tree.AddItem( 4 );
    Tree.AddItem(100);
    Tree.AddItem(102);
  
    Tree.ResetTree();
    
    
    Tree.AddItem(5);
    Tree.AddItem( 7 );
    Tree.AddItem( 3 );
    Tree.AddItem( 97 );
    Tree.AddItem( 9 );
    Tree.AddItem( 1 );
    Tree.AddItem( 2 );
    Tree.AddItem( 4 );
    Tree.AddItem(100);
    Tree.AddItem(102);
    Tree.DeleteItem(4);

// This prints in the tree format
    Tree.PrintTree( );
    
    
    return 0;
}
