#include <iostream>
using namespace std;

class bst_node {
 public:
  string s_id;
  string name;
  double score;

  bst_node *left, *right;
  bst_node() {
    s_id = "00000000";
    name = "Null";
    score = 0;
  }
  bst_node(string s1, string s2, double n) {
    s_id = s1;
    name = s2;
    score = n;
  }
  void set_data(string s1, string s2, double n) {
    s_id = s1;
    name = s2;
    score = n;
  }
};

class bst_tree {
  bst_node *root;
  int csize;

 public:
  bst_tree() {}
  void insert_node(bst_node t);
  void show_inorder();
  bst_node search(string tid);
};

int main() {}