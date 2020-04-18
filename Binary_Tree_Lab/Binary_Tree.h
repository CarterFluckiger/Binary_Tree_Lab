#ifndef Binary_Tree_h
#define Binary_Tree_h

#include <iostream>

//Node Struct
struct Nodetype;
//I did a type def of int to make it more versitile if I revisit this project
typedef int Itemtype;

class BiTree
{
public:
    //Pre Conditions- None
    //Post Conditions- Sets root to nullptr
    BiTree( );
    //Pre Conditions- None
    //Post Conditions- Empties the list and deconstructs it
    ~BiTree( );
    
    //Pre Conditions- Has an int for to fufill the arguement
    //Post Conditions- Calls Insert function that is private
    void AddItem(Itemtype item);
    
    //The IsFull and IsEmpty are functions that could be used in a revist of this project so I left them for if I come back for it
    
    //Pre Conditions- None
    //Post Conditions- Returns a boolean value on whether or not the tree is empty or not
    bool IsEmpty( );
    //Pre Conditions- None
    //Post Conditions- Returns a boolean value on whether or not the tree is empty or not
    bool IsFull( );
    //Pre Conditions- None
     //Post Conditions- Sets root = nullptr
    void MakeEmpty( );
    //Pre Conditions- None
     //Post Conditions- Calls MakeEmpty function and resets the list
    void ResetTree( );
       //Pre Conditions- That numbers have been added to the tree
       //Post Conditions- Calls a private print function to print in numerical order
    void PrintFTree( );
    //Pre Conditions- That numbers have been added to the tree
    //Post Conditions- Calls a private funtion to print the tree in a tree format
    void PrintTree( );
    //Pre Conditions-That there are numbers in the tree
    //Post Conditions- Calls a private funtion that prints the contents of the tree in reverse numberical order
    void PrintRTree();
    
    //Pre Conditions- Has a int in the argument to delete
    //Post Conditions- Calls the private Delete function
    void DeleteItem(Itemtype item);
  
    
private:
    //Pointer for the root int on the Binary Tree
    Nodetype* root;
    
    //Pre Conditions- Needs pointer argument and item arguement
    //Post Conditions- Uses recursion to find the place to insert the item and inserts it
    void Insert( Nodetype* &node, Itemtype item );
    //Pre Conditions- Needs pointer argument and item arguement
    //Post Conditions- Moves through the function using recursion and then finds the correct number and calls DeleteNode
    void Delete( Nodetype* &node, Itemtype item );
    //Pre Conditions- Has Nodetype pointer argument fufilled
    //Post Conditions-Figures out the situation is of the Nodes left and right pointers.  Then does the correct sequence to delete the node but keep
    //the tree in tact
    void DeleteNode( Nodetype* &node );
    
    
    //Print methods
    //Pre Conditions- Has Nodetype pointer arguement fufilled
    //Post Conditions- Prints tree numeric order format
    void PrivatePrintFTree( Nodetype* &node );
    //Pre Conditions- Has Nodetype pointer arguement fufilled
    //Post Conditions- Prints tree in tree format
    void PrivateTPrint( Nodetype* &node );
    //Pre Conditions- Has Nodetype pointer arguement fufilled
    //Post Conditions-Prints tree in reverse numeric order
    void PrivateRPrint( Nodetype* &node );
    
};

#endif /* Binary_Tree_h */
