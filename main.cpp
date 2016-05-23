#include <iostream>
#include "FibHeap.h"

using namespace std;

int main(int argc, char **argv) {
    FibHeap fibheap;
    fib_heap_t heap1,heap2;
    heap1.min = fibheap.make_heap();
    heap2.min = fibheap.make_heap();
    fibheap.insert(&heap1,31);
    fibheap.insert(&heap1,32);
    fibheap.insert(&heap1,33);
    fibheap.print_root_list(heap1);
    fibheap.insert(&heap2,23);
    fibheap.insert(&heap2,24);
    fibheap.insert(&heap2,25);
    fibheap.heap_union(&heap1,&heap2);
    fibheap.print_root_list(heap1);
    node* minNode = fibheap.minimum(&heap1);
    cout<<minNode->key;
    fibheap.heap_link(&heap1,heap1.min->right,heap1.min->right->right);
    fibheap.print_root_list(heap1);
    return 0;
}
