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

    /*
    fibheap.make_heap();
    fibheap2.make_heap();
    cout << "heap initialize with min pointer -> null... \n";
    fibheap.insert(31);
    fibheap.insert(32);
    fibheap.insert(33);
    fibheap.print_root_list();
    fibheap2.insert(34);
    fibheap2.insert(35);
    fibheap2.insert(36);
    fibheap.heap_union(fibheap2.get_min_node());
    fibheap.print_root_list();
    fibheap2.print_root_list();
    */
    return 0;
}
