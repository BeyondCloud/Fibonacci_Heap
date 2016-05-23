#include <iostream>
#include "FibHeap.h"

using namespace std;

int main(int argc, char **argv) {
    FibHeap fibheap;
    fibheap.make_heap();
    cout << "heap initialize with min pointer -> null... \n";
    fibheap.insert(31);
    fibheap.insert(32);
    fibheap.insert(33);
    fibheap.print_root_list();

    return 0;
}
