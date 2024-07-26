#include <iostream>
using namespace std;

class node {
 public:
  int score;
  node *link;

  node() { score = 0; }
  node(int n) { score = n; }
  void setData(int n) { score = n; }
};

class LL {
  node *head, *tail;

 public:
  LL() {
    head = NULL;
    tail = NULL;
  }
  void push(int data) {
    node *tmp = new node(data);
    tmp->link = head;
    head = tmp;
  }

  node deleteHead() {
    node *t, tmp;
    t = head;
    tmp = *head;
    head = head->link;
    delete t;

    if (head == NULL) {
      tail = NULL;
    }
    return tmp;
  }

  void invert() {
    node *newHead, *oldHead, *tmp;
    newHead = NULL;
    oldHead = head;

    while (oldHead != NULL) {
      tmp = newHead;
      newHead = oldHead;
      oldHead = oldHead->link;
      newHead->link = tmp;
    }
    tail = head;
    head = newHead;
  }

  void print() {
    node *tmp = head;
    while (tmp != NULL) {
      cout << tmp->score << " ";
      tmp = tmp->link;
    }
  }
};

int main() {
  LL ll;
  ll.push(20);
  ll.push(5);
  ll.push(15);
  ll.push(85);

  ll.print();

  ll.invert();
  ll.print();

  return 0;
}