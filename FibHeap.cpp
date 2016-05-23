#include "FibHeap.h"
#include <string.h>
#include <iostream>
using namespace std;

FibHeap::FibHeap() {
}
FibHeap::~FibHeap() {

}
node* FibHeap::create_node(int key)
{
    node* new_node   = new node;
    new_node->degree = 0;
    new_node->parent = NULL;
    new_node->child  = NULL;
    new_node->left   = new_node;
    new_node->right  = new_node;
    new_node->mark   = false;
    new_node->key    = key;
    return new_node;
}
node* FibHeap::make_heap() {
    node* np;
    np = NULL;
    return np;
}


node* FibHeap::insert(node* min, int key)
{
    node* node_to_insert = new node;
    node_to_insert = create_node(key);
    if (min != NULL)
    {
        (min->left)->right = node_to_insert;
        node_to_insert->right = min;
        node_to_insert->left = min->left;
        min->left = node_to_insert;
        if (node_to_insert->key < min->key)
            min = node_to_insert;
    }
    else
    {
            cout<<"first insert\n";
            min = node_to_insert;
    }
    if(node_to_insert == NULL)
        cout<<"NULL";
    cout << "key " <<node_to_insert->key<<" inserted\n";
    return min;
}

void FibHeap::print_root_list(node *start_node)
{
    cout << "Here is the roots list:\n";
    node* temp = start_node;
    do
    {
        cout<<temp->key<<"\t";
        temp = temp->right;
    }while(temp != start_node);
    cout<<endl;
}
void FibHeap::heap_union(node *min1 ,node *min2)
{
   if(min1 == NULL or min2 == NULL)
        return;
   min1->right->left  = min2->left;
   min2->left->right = min1->right;
   min1->right = min2;
   min2->left = min1;
   if(min2 -> key < min1-> key)
    min1 = min2;
}
/*
1   H =MAKE-FIB-HEAP()
2   H.min =H1.min
3   concatenate the root list of H2 with the root list of H
4   if (H1.min == NIL) or (H2.min „j NIL and H2.min .key < H1.min.key)
5          H.min =H2.min
6   H.n =H1.n + H2.n
7   return H
*/
