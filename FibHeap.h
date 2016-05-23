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
  void make_heap();
  void insert(int);
  void print_root_list();
  node* get_min_node();
private:
  node *min;
};
