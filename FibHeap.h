
struct node
{
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
    bool mark;
    int key;
};
struct fib_heap_t{
    struct node* min;
    int n;
};
class FibHeap {

public:
  FibHeap();
  ~FibHeap();
  node* create_node(int);
  node* make_heap();
  void insert(fib_heap_t* , int);
  void print_root_list(fib_heap_t);
  void heap_union(fib_heap_t*,fib_heap_t*);
};
