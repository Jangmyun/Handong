#include <iostream>
using namespace std;

class node {
 public:
  string s_id;
  string name;
  double score;
  node *left, *right;

  node() {}
  node(string id, string n, double s) {
    s_id = id;
    name = n;
    score = s;
  }

  void set_data(string i, string n, double s) {
    s_id = i;
    name = n;
    score = s;
  }
};

class binarySearchTree {
  node *root;
  int csize;

 public:
  binarySearchTree() { root = NULL; }
  void insert_node(node t);
  void show_inorder();
  node search(string tid);
};

node binarySearchTree::search(string tid) {
  node *p;
  p = root;

  if (root == NULL) {
    node tmp("00000000", "None", -1);
    cout << "The key " << tid << " does not exist.\n";
    return tmp;
  }

  while (1) {
    if (p->s_id == tid) return *p;

    if (p->s_id < tid) {
      if (p->right == NULL) {
        cout << "The key " << tid << " does not exist.\n";
      } else {
        p = p->right;
      }
    } else {
      if (p->right == NULL) {
        cout << "The key " << tid << " does not exist.\n";
      } else {
        p = p->left;
      }
    }
  }
}

void binarySearchTree::insert_node(node t) {
  node *p;
  node *tmp;

  tmp = new node;
  *tmp = t;
  tmp->left = NULL;
  tmp->right = NULL;

  if (root == NULL) {
    root = tmp;
    return;
  }

  p = root;
  while (1) {
    if (p->s_id == t.s_id) {
      cout << "Insertion Faild" << endl;
      return;
    }
    if (p->s_id < t.s_id) {
      if (p->right == NULL) {
        p->right = tmp;
        return;
      } else {
        p = p->right;
      }
    } else {
      if (p->left == NULL) {
        p->left = tmp;
        return;
      } else {
        p = p->left;
      }
    }
  }
}

void inorder(node *p) {
  if (p == NULL) {
    return;
  }
  inorder(p->left);
  cout << p->s_id << " : " << p->name << " : " << p->score << endl;
  inorder(p->right);
}

void binarySearchTree::show_inorder() { inorder(root); }

int main() {
  node temp;
  binarySearchTree t1;
  temp.set_data("21900013", "Kim", 6.5);
  t1.insert_node(temp);
  temp.set_data("21900136", "Lee", 8.8);
  t1.insert_node(temp);
  temp.set_data("21900333", "Park", 9.2);
  t1.insert_node(temp);
  temp.set_data("21800442", "Choi", 7.1);
  t1.insert_node(temp);
  temp.set_data("21900375", "Ryu", 5.4);
  t1.insert_node(temp);
  temp.set_data("21700248", "Cho", 6.3);
  t1.insert_node(temp);
  cout << "\n\n Node List : inorder sequence \n";
  t1.show_inorder();
  string s_key = "21800442";
  temp = t1.search(s_key);
  cout << "\n -- " << s_key << "'s record ---" << endl;
  cout << " Student ID : " << temp.s_id << endl;
  cout << " Student Name : " << temp.name << endl;
  cout << " Score : " << temp.score << endl;
  return 0;
}