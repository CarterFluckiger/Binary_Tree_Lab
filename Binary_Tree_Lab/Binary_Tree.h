#ifndef Binary_Tree_h
#define Binary_Tree_h

#include <iostream>

struct Nodetype;

typedef int Itemtype;


class BiTree
{
public:
    BiTree( );
    ~BiTree( );
    
//Add and Delete items
    void AddItem(Itemtype item);
    bool IsEmpty( );
    bool IsFull( );
    int GetLength( );
    Itemtype GetItem( );
    void PutItem(Itemtype item);
    void MakeEmpty( );
    void ResetTree( );
    void PrintFTree( );
    void PrintTree( );
    void PrintRTree();
    
       void DeleteItem(Itemtype item);
    void DeleteNode();
    
private:
    
    Nodetype* root;
    int length;
    
    void Insert( Nodetype* &node, Itemtype item );
    void Delete( Nodetype* &node, Itemtype item );
    void DeleteNode( Nodetype* &node );
    
    
    //Print methods
    void PrivatePrintFTree( Nodetype* &node );
    void PrivateTPrint( Nodetype* &node );
    void PrivateRPrint( Nodetype* &node );
    
};

#endif /* Binary_Tree_h */
