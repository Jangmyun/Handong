#include <iostream>
using namespace std;

class node {
  string name;
  double score;
  node *left, *right;

 public:
  string getName() { return this->name; }
  double getScore() { return this->score; }
  node *getLeft() { return this->left; }
  node *getRight() { return this->right; }
};

// 주어진 p를 root로 하는 binary tree 를 inorder traverse
void inorderTraverse(node *p) {
  if (p == NULL) {
    return;
  }

  inorderTraverse(p->getLeft());
  cout << p->getName() << " : " << p->getScore() << endl;
  inorderTraverse(p->getRight());
}

void preorderTraverse(node *p) {
  if (p == NULL) {
    return;
  }

  cout << p->getName() << " : " << p->getScore() << endl;
  preorderTraverse(p->getLeft());
  preorderTraverse(p->getRight());
}

void postorderTraverse(node *p) {
  if (p == NULL) {
    return;
  }

  postorderTraverse(p->getLeft());
  postorderTraverse(p->getRight());
  cout << p->getName() << " : " << p->getScore() << endl;
}

int main() { return 0; }