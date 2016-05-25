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
    fibheap.print_root_list(heap1);
    fibheap.insert(&heap2,23);
    fibheap.insert(&heap2,24);
    fibheap.insert(&heap2,25);
    heap12 = fibheap.heap_union(&heap1,&heap2);
    fibheap.print_root_list(heap12);
    node* minNode = fibheap.minimum(&heap12);
    cout<<"The min key of heap12 is :"<<minNode->key<<endl;
    cout<<"The element count heap12 is :"<<heap12.n<<endl;
    cout<<heap12.min->key;
    fibheap.consolidate(&heap12);
//    fibheap.heap_link(&heap1,heap1.min->right,heap1.min->right->right);
//    cout<<"Link min->right to min->right->right\n";
//    fibheap.print_root_list(heap1);
//    fibheap.consolidate(&heap1);
//    fibheap.print_root_list(heap1);

    return 0;
}
