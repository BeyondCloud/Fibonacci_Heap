#include <iostream>
#include "FibHeap.h"

using namespace std;

int main(int argc, char **argv) {
    FibHeap fibheap;
    node *n1 = fibheap.create_node(31);
    node *heap1 = fibheap.make_heap();
    node *heap2 = fibheap.make_heap();
    heap1 = fibheap.insert(heap1,n1);
    n1 = fibheap.create_node(32);
    heap1 = fibheap.insert(heap1,n1);
    n1 = fibheap.create_node(33);
    heap1 = fibheap.insert(heap1,n1);
    fibheap.print_root_list(heap1);

    n1 = fibheap.create_node(26);
    heap2 = fibheap.insert(heap2,n1);
    n1 = fibheap.create_node(27);
    heap2 = fibheap.insert(heap2,n1);
    n1 = fibheap.create_node(28);
    heap2 = fibheap.insert(heap2,n1);

    fibheap.heap_union(heap1,heap2);
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
