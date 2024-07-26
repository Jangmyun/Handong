#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class node {
 public:
  string name;
  double score;
  node *left, *right;
  void set_data(string n, double s) {
    name = n;
    score = s;
  }
};

class mytree {
  node *root;
  int nodeCount;

  mytree() {
    root = NULL;
    nodeCount = 0;
  }
  int insert_root(node t);
  int insert_left(string tname, node t);
  int insert_right(string tname, node t);
  double score_sum();
  void print_data_inorder();
  void nonrecursive_inorder();
  void levelorder();
};

int mytree::insert_root(node t) {
  if (root != NULL) {
    return 0;
  }
  node *p;
  p = new node;
  *p = t;
  p->left = NULL;
  p->right = NULL;
  root = p;
  nodeCount++;
  return 1;
}

int node_insert_left(node *p, string tname, node t);
int node_insert_right(node *p, string tname, node t);

int mytree::insert_left(string tname, node t) {
  int result;
  result = node_insert_left(root, tname, t);
  if (result == 1) nodeCount++;
  return result;
}
int node_insert_left(node *p, string tname, node t) {
  if (p == NULL) return 0;
  if (p->name == tname) {
    if (p->left != NULL) {
      return -1;
    }
    node *tmp;
    tmp = new node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;
    p->left = tmp;
    return 1;
  } else {
    int result;
    result = node_insert_left(p->left, tname, t);
    if (result != 0) return result;
    return node_insert_left(p->right, tname, t);
  }
}

int mytree::insert_right(string tname, node t) {
  int result;

  result = node_insert_right(root, tname, t);
  if (result == 1) nodeCount++;
  return result;
}
int node_insert_right(node *p, string tname, node t) {
  if (p == NULL) return 0;
  if (p->name == tname) {
    if (p->left != NULL) return -1;
    node *tmp;
    tmp = new node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;
  } else {
    int result = node_insert_right(p->left, tname, t);
    if (result != 0) return result;
    return node_insert_right(p->right, tname, t);
  }
}

double sum_all_nodes(node *p);
double mytree::score_sum() { return sum_all_nodes(root); }
double sum_all_nodes(node *p) {
  if (p == NULL) return 0;
  return sum_all_nodes(p->left) + sum_all_nodes(p->right) + p->score;
}

void inorder_print(node *p);
void mytree::print_data_inorder() { inorder_print(root); }
void inorder_print(node *p) {
  if (p == NULL) return;
  inorder_print(p->left);
  cout << p->name << " : " << p->score << endl;
  inorder_print(p->right);
}

void mytree::nonrecursive_inorder() {
  stack<node *> s;
  node *tmp;

  tmp = root;
  while (1) {
    while (tmp != NULL) {
      s.push(tmp);
      tmp = tmp->left;
    }
    while (tmp == NULL) {
      if (s.empty()) return;
      tmp = s.top();
      s.pop();
    }
    cout << tmp->name << " : " << tmp->right << endl;
    tmp = tmp->right;
  }
}

void mytree::levelorder() {
  queue<node *> q;
  node *tmp;
  if (root == NULL) {
    return;
  }
  q.push(root);
  while (1) {
    if (q.empty()) return;
    tmp = q.front();
    q.pop();
    cout << tmp->name << " : " << tmp->score << endl;
    if (tmp->left != NULL) q.push(tmp->left);
    if (tmp->right != NULL) q.push(tmp->right);
  }
}

int main() { return 0; }