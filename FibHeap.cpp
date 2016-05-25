#include "FibHeap.h"
#include <math.h>
#include <limits.h>
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
node* FibHeap::make_heap()
{
    node* np;
    np = NULL;
    return np;
}
node* FibHeap::minimum(fib_heap_t* h)
{
     return h->min;
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
    heap->n++;
    cout << "num of element = " << heap->n << endl;
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
/*    node* np;
    node* H = InitializeHeap();
    H = H1;
    (H->left)->right = H2;
    (H2->left)->right = H;
    np = H->left;
    H->left = H2->left;
    H2->left = np;
    return H;
    */
fib_heap_t FibHeap::heap_union(fib_heap_t *heap1 ,fib_heap_t *heap2)
{
    if(heap1->min == NULL )
        return *heap2;
    if(heap2->min == NULL )
        return *heap1;
    fib_heap_t new_heap;
    new_heap.min = make_heap();
    new_heap = *heap1;
    new_heap.min->right->left  = heap2->min->left;
    heap2->min->left->right = new_heap.min->right;
    new_heap.min->right = heap2->min;
    heap2->min->left = new_heap.min;
    if(heap2->min -> key < new_heap.min-> key)
       new_heap.min = heap2->min;
    new_heap.n =heap1->n + heap2->n;
    return new_heap;
    /*
    fib_heap_t new_heap;
    heap1->min = fibheap.make_heap();
    (new_heap->min->left)->right = heap2->min;
    (heap2->min->left)->right = heap1->min;
    heap->min = heap1->min->left;
    heap1->min->left = heap2->min->left;
    heap2->min->left = new_heap->min;
    return new_heap;
    */
    /*
   fib_heap_t new_heap;
   new_heap->min = fibheap.make_heap();
   if(heap1->min == NULL or heap2->min == NULL)
        return;
   heap1->min->right->left  = heap2->min->left;
   heap2->min->left->right = heap1->min->right;
   heap1->min->right = heap2->min;
   heap2->min->left = heap1->min;
   if(heap2->min -> key < heap1->min-> key)
      heap1->min = heap2->min;
    heap1->n += heap2->n;
    */

}
/*
remove y from the root list of H
2   make y a child of x, incrementing x.degree
3   y.mark =FALSE

*/
//link y to x
 void FibHeap::heap_link(fib_heap_t* heap, node* y,node* x)
 {

    if(y == heap->min)
    {
        cout<<"cannot link min node to other node\n";
        return;
    }

    y->left->right = y->right;
    y->right->left = y->left;

    if (x->right == x) //if there is only one root
        heap->min = x;
    y->left = y;
    if (x->child == NULL)
    {
        y->right = y;
        y->parent = x;
        x->child = y;
    }
    else
    {
        y->right = x->child;
        y->left = (x->child)->left;
        x->child->left->right = y;
        x->child->left = y;
    }
    x->degree++;
}

void FibHeap::consolidate(fib_heap_t* heap)
{
    int vals = heap->min->key;
    int D = ceil(log2(heap->n));
    node* A[D];
    for(int i = 0;i < D ;i++)
        A[i] = NULL;
    node* w = heap->min;
    node* x;

    do
    {
        x = w;
        int degree = x->degree;
        while(A[degree] != NULL)
        {
            node* y = A[degree];
            if(x->key > y->key)
            {
                int tmp = x->key;
                x->key = y->key;
                y->key = tmp;
                if(y == heap->min)
                    heap->min = x;
            }
            heap_link(heap, y, x);
            cout<<"link "<< y->key << "to "<<x->key<<endl;
            A[degree] = NULL;
            degree++;
        }
        A[degree]  = x;

        w = w->right;
    }while(w != heap->min);
    heap->min = NULL;
    for(int i = 0;i <D;i++)
    {
        if (A[i] != NULL)
        {
             if(heap->min == NULL)
            {
             heap->min = A[i];
             heap->min->left = heap->min;
             heap->min->right = heap->min;
            }
            else
            {
                A[i]->right = heap->min;
                A[i]->left = heap->min->left;
                heap->min->left->right = A[i];
                heap->min->left = A[i];
                if(A[i]->key < heap->min->key)
                    heap->min = A[i];
            }
        }


    }
}
/*
BINOMIAL-HEAP-DECREASE-KEY(H, x, k)
1   if k > x.key
2         error new key is greater than current
3   x.key =k
4   y =x
5   z =y.p
6   while z != NIL and y.key < z.key
7            exchange y.key  z.key
8            /* exchange satellite fields in y and z
9            y =z
10          z =y.p
*/

void FibHeap::decrease_key(fib_heap_t *heap,node *from ,int to)
{
    cout <<"decrease key "<< from->key << " -> " << to <<endl;
    if(to > from->key)
    {
        cout << "new key is greater than current";
        return;
    }
    from->key = to;
    node* y = from;
    node* z = y->parent;
    while(z != NULL and y->key <z->key)
    {
        int tmp = y->key;
        y->key = z->key;
        z->key = tmp;
        y = z ;
        z = y->parent;
    }

}

