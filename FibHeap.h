struct node
{
    int n;
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
    bool mark;
    int key;
};
class FibHeap {

public:
  FibHeap();
  ~FibHeap();
  node* create_node(int);
  node* make_heap();
  node* insert(node* , int);
  void print_root_list(node *);
  void heap_union(node*,node*);
};
