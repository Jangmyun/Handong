#include <iostream>
using namespace std;
#define HSIZE 100

class element {
 public:
  string name;
  double score;
  void set_data(string n, double s) {
    name = n;
    score = s;
  }
};

class myheap {
  element h[HSIZE];
  int csize;

 public:
  myheap() { csize = 0; }
  myheap(element a[], int n);
  int h_size() { return csize; }
  void insert_heap(element t) {
    int k;
    csize++;
    k = csize;
    // parent 값 (h[k/2])이 주어진 값 보다 작으면
    while ((k != 1) && (t.score > h[k / 2].score)) {
      h[k] = h[k / 2];
    }
  }
  element delete_heap();
  bool heap_full() { return csize >= HSIZE - 1 ? true : false; }
  bool heap_empty() { return csize == 0 ? true : false; }
  void adjust(int t_root);
};

int main() { return 0; }