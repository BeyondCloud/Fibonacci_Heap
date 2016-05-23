
class FibHeap {

public:
  FibHeap();
  FibHeap(int initSize);
  ~FibHeap();
  void make_heap();

private:
  int size;
  int *tbl;
  int num;
};
