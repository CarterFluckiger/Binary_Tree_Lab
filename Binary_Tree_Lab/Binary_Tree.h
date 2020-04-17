#ifndef Binary_Tree_h
#define Binary_Tree_h

#include <iostream>

struct Nodetype;

typedef int Itemtype;

enum LeftorRight{Greater, Equal, Less };

class BiTree
{
public:
    BiTree();
    ~BiTree();
    
//Add and Delete items
    void AddItem(Itemtype item);
    bool IsEmpty();
    bool IsFull();
    int GetLength();
    Itemtype GetItem();
    void PutItem(Itemtype item);
    void MakeEmpty();
    void ResetTree();
    void PrintTree( );
    
    void DeleteItem(Itemtype item);
    void DeleteNode(Itemtype item);
    
private:
    Nodetype* root;
    int length;
    
    void Insert( Nodetype* &node, Itemtype item );
    void Delete( Nodetype* &node, Itemtype item );
    void DeleteNodePrivate( Itemtype item, Nodetype* parent );
    
    
    //Print methods
    void PrivatePrintTree( Nodetype* &node );
    void TPrint();
    void RPrint();
    
};

#endif /* Binary_Tree_h */
