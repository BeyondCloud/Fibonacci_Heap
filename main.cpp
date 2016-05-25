#include <iostream>
#include "FibHeap.h"

using namespace std;

int main(int argc, char **argv) {
    FibHeap fibheap;
    fib_heap_t heap1,heap2,heap12;
    heap1.min = fibheap.make_heap();
    heap2.min = fibheap.make_heap();
    heap12.min = fibheap.make_heap();
    fibheap.insert(&heap1,31);
    fibheap.insert(&heap1,32);
    fibheap.insert(&heap1,33);
    fibheap.insert(&heap1,36);
    fibheap.insert(&heap1,39);
    fibheap.insert(&heap1,42);
    fibheap.insert(&heap1,47);
    fibheap.print_root_list(heap1);
    fibheap.insert(&heap2,23);
    fibheap.insert(&heap2,24);
    fibheap.insert(&heap2,25);
    heap12 = fibheap.heap_union(&heap1,&heap2);
    fibheap.print_root_list(heap12);
    node* minNode = fibheap.minimum(&heap12);
    cout<<"The min key of heap12 is :"<<minNode->key<<endl;
    cout<<"The element count heap12 is :"<<heap12.n<<endl;
    fibheap.consolidate(&heap12);
    fibheap.print_root_list(heap12);
    fibheap.decrease_key(&heap12,heap12.min->right->child,2);
    fibheap.print_root_list(heap12);
    minNode = fibheap.extract_min(&heap12);
    cout<<"tree after extract min:\n";
    fibheap.print_root_list(heap12);
    cout<<heap12.min->key;
    cout<<"cut heap12 min child \n";
    fibheap.cut(&heap12,heap12.min->child,heap12.min);
    fibheap.print_root_list(heap12);
    return 0;
}
