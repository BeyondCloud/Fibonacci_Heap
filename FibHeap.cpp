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


void FibHeap::insert(fib_heap_t *heap, int key)
{
    node* node_to_insert = new node;
    node_to_insert = create_node(key);
    if (heap->min != NULL)
    {
        (heap->min->left)->right = node_to_insert;
        node_to_insert->right = heap->min;
        node_to_insert->left = heap->min->left;
        heap->min->left = node_to_insert;
        if (node_to_insert->key < heap->min->key)
            heap->min = node_to_insert;
    }
    else
    {
            cout<<"first insert\n";
            heap->min = node_to_insert;
    }
    if(node_to_insert == NULL)
        cout<<"NULL";
    cout << "key " <<node_to_insert->key<<" inserted\n";

}

void FibHeap::print_root_list(fib_heap_t heap)
{
    cout << "Here is the roots list:\n";
    node* temp = heap.min;
    do
    {
        cout<<temp->key<<"\t";
        temp = temp->right;
    }while(temp != heap.min);
    cout<<endl;
}
void FibHeap::heap_union(fib_heap_t *heap1 ,fib_heap_t *heap2)
{
   if(heap1->min == NULL or heap2->min == NULL)
        return;
   heap1->min->right->left  = heap2->min->left;
   heap2->min->left->right = heap1->min->right;
   heap1->min->right = heap2->min;
   heap2->min->left = heap1->min;
   if(heap2->min -> key < heap1->min-> key)
    heap1->min = heap2->min;
}
