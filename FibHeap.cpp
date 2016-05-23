#include "FibHeap.h"
#include <string.h>
#include <iostream>
using namespace std;

FibHeap::FibHeap() {
}
FibHeap::~FibHeap() {

}
void FibHeap::make_heap() {
        min = NULL;
}


void FibHeap::insert(int key)
{
    node *new_node = new node;
    new_node->degree = 0;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->mark = false;
    new_node->key = key;
    if (min != NULL)
    {
        (min->left)->right = new_node;
        new_node->right = min;
        new_node->left = min->left;
        min->left = new_node;
        if (new_node->key < min->key)
            min = new_node;
    }
    else
    {
            new_node->left = new_node;
            new_node->right = new_node;
            cout<<"first insert\n";
            min = new_node;
    }
    cout << "key " <<new_node->key<<" inserted\n";
}
node* FibHeap::get_min_node()
{
    return min;
}
void FibHeap::print_root_list()
{
    cout << "Here is the roots list:\n";
    node* temp =min;
    do
    {
        cout<<temp->key<<"\t";
        temp = temp->right;
    }while(temp != min);
}
