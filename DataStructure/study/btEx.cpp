#include <iostream>
using namespace std;

class node {
 public:
  string name;
  int score;
  node *left, *right;
  void set_date(string s, double n) {
    name = s;
    score = n;
  }
};
class my_queue {
  node *q[100];
  int front, rear;

 public:
  my_queue() {
    front = 0;
    rear = 0;
  }
  void insert_q(node *p) {
    if (!queue_full()) {
      q[rear] = p;
      rear = (rear + 1) % 100;
    }
  }
  node *delete_q() {
    node *tmp;
    if (!queue_empty()) {
      tmp = q[front];
      front = (front + 1) % 100;
      return tmp;
    } else {
      return tmp;
    }
  }
  bool queue_empty() {
    if (rear == front) {
      return true;
    }
    return false;
  }

  bool queue_full() {
    if ((rear + 1) % 100 == front) {
      return true;
    }
    return false;
  }
};

int nodeInsertLeft(node *p, string tName, node tNode) {
  if (p == NULL) {
    return 0;
  }
  if (p->name == tName) {
    if (p->left != NULL) {
      return -1;
    }

    node *t;
    t = new node;
    *t = tNode;
    p->left = t;
    return 1;
  } else {
    int result = nodeInsertLeft(p->left, tName, tNode);
    if (result != 0) {
      return result;
    }
    return nodeInsertLeft(p->right, tName, tNode);
  }
}

void inorderPrint(node *p) {
  if (p == NULL) {
    return;
  }

  inorderPrint(p->left);
  cout << p->name << " : " << p->score << endl;
  inorderPrint(p->right);
}

class my_tree {
 public:
  int node_count;
  node *root;

  my_tree() {
    node_count = 0;
    root = NULL;
  }
  int insert_root(node t);
  int insert_left(string tname, node t) {
    int result = nodeInsertLeft(root, tname, t);
    if (result == 1) {
      node_count++;
    }
    return result;
  }
  int insert_right(string tname, node t);

  double score_sum();
  double score_average();
  void printDataInOrder() { inorderPrint(root); }
  void print_data_preorder();
  void print_data_postorder();
  void printDataLevelOrder();
};

void my_tree::printDataLevelOrder() {
  my_queue q1;
  node *t;
  if (root == NULL) {
    return;
  }
  q1.insert_q(root);
  while (1) {
    if (q1.queue_empty()) {
      return;
    }
    t = q1.delete_q();
    cout << t->name << " : " << t->score << endl;
    if (t->left != NULL) {
      q1.insert_q(t->left);
    }
    if (t->right != NULL) {
      q1.insert_q(t->right);
    }
  }
}

int main() { return 0; }