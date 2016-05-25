
struct node
{
    int degree = 0;
    node* parent;
    node* child;
    node* left;
    node* right;
    bool mark;
    int key;
};
struct fib_heap_t{
    struct node* min;
    int n = 0;
};
class FibHeap {

public:
  FibHeap();
  ~FibHeap();
  node* create_node(int);
  node* make_heap();
  node* minimum(fib_heap_t*);
  void insert(fib_heap_t* , int);
  void print_root_list(fib_heap_t);
  fib_heap_t heap_union(fib_heap_t*,fib_heap_t*);
  void heap_link(fib_heap_t*, node*,node*);
  void consolidate(fib_heap_t*);
  void decrease_key(fib_heap_t*,node*,int);
  node* extract_min(fib_heap_t*);
  void cut(fib_heap_t*,node*,node*);
  void cascading_cut(fib_heap_t*,node*);
};
