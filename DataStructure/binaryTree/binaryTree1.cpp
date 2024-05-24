#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
 public:
  string name;
  double score;
  Node *left, *right;
  void set_date(string s, double n) {
    name = s;
    score = n;
  }
};

// 성공시 1, 해당 Node없으면 0 , Node는 있는데 left가 NULL이 아닌 경우 -1 리턴
int node_insert_left(Node *p, string tName, Node tNode) {
  if (p == NULL) {  // root가 NULL이면 0리턴
    return 0;
  }
  if (p->name == tName) {  // tName과 일치하는 노드를 찾았을 때
    if (p->left !=
        NULL) {  // tName과 일치하는 노드의 left Node 가 이미 있으면 -1 리턴
      return -1;
    }
    Node *t;
    t = new Node;
    *t = tNode;
    t->left = NULL;
    t->right = NULL;
    p->left = t;
    return 1;
  } else {
    int result = node_insert_left(p->left, tName, tNode);
    if (result != 0) {
      return result;
    }
    return node_insert_left(p->right, tName, tNode);
  }
}

int node_insert_right(Node *p, string tName, Node tNode) {
  if (p == NULL) {
    return 0;
  }
  if (p->name == tName) {
    if (p->right != NULL) {
      return -1;
    }
    Node *t;
    t = new Node;
    t->left = NULL;
    t->right = NULL;
    p->right = t;
    return 1;
  } else {
    int result = node_insert_right(p->left, tName, tNode);
    if (result != 0) {
      return result;
    }
    return node_insert_right(p->right, tName, tNode);
  }
}

double sum_allNodes(Node *p) {
  if (p == NULL) {
    return 0;
  }
  return sum_allNodes(p->left) + sum_allNodes(p->right) + p->score;
}

void inorder_print(Node *p) {
  if (p == NULL) {
    return;
  }

  inorder_print(p->left);
  cout << p->name << " : " << p->score << endl;
  inorder_print(p->right);
}

Node *make_copy(Node *p) {
  Node *t;
  if (p == NULL) {
    return NULL;
  }
  t = new Node;
  *t = *p;
  t->left = make_copy(p->left);
  t->right = make_copy(p->right);
  return t;
}

bool equal_test(Node *p1, Node *p2) {
  // 둘다 NULL이면 true
  if ((p1 == NULL) && (p2 == NULL)) return true;
  // 둘 중에 하나만 NULL이면 false
  if (p1 == NULL) return false;
  if (p2 == NULL) return false;
  // 두 Node 값이 다르면 false
  if (p1->name != p2->name) return false;
  if (p1->score != p2->score) return false;

  // 각 원소의 left와 right에 대해 recursive
  if (equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right)) {
    return true;
  } else {
    return false;
  }
}

class MyTree {
 public:
  int nodeCount;
  Node *root;
  MyTree() {
    nodeCount = 0;
    root = NULL;
  }
  int insert_root(Node t) {  // 실패시 0 성공시 1 리턴
    // root가 NULL이 아니면 실패 (이미 Root에 뭔가 있음)
    if (root != NULL) {
      return 0;
    }
    // Node 공간 생성
    Node *p;
    p = new Node;
    *p = t;
    p->left = NULL;
    p->right = NULL;
    // 생성한 Node를 root로
    root = p;
    nodeCount++;
    return 1;
  }

  // name이 tname인 node를 찾고 그 node 왼쪽에 t추가
  int insert_left(string tName, Node t) {
    int result;

    result = node_insert_left(root, tName, t);
    if (result == 1) {
      nodeCount++;
    }
    return result;
  }
  int insert_right(string tName, Node t) {
    int result;
    result = node_insert_right(root, tName, t);
    if (result == 1) {
      nodeCount++;
    }
    return result;
  }

  double score_sum() { return sum_allNodes(root); }
  double score_average() { return score_sum() / nodeCount; };
  void printData() { inorder_print(root); }

  // non recursive inorder traversal ( stack 사용 )
  void nonRecursiveInorder() {
    stack<Node *> s;
    Node *t;
    t = root;
    // root 부터 반복
    while (1) {
      // 현재 node부터 왼쪽 끝 노드 찾을 때까지 node를 스택에 넣기
      while (t != NULL) {
        s.push(t);
        t = t->left;
      }
      // stack이 empty면 리턴
      while (t == NULL) {
        if (s.empty()) {
          return;
        }
        // stack에서 한개 원소 pop
        t = s.top();
        s.pop();
      }
      cout << t->name << " : " << t->score << endl;
      t = t->right;
    }
  }

  // level order ( queue 사용 )
  void levelOrder() {
    queue<Node *> q;
    Node *t;

    // root NULl이면 리턴
    if (root == NULL) {
      return;
    }
    // root를 q에 넣고 시작
    q.push(root);
    while (1) {
      // q가 empty면 종료
      if (q.empty()) {
        return;
      }
      // q에서 한개 원소 pop
      t = q.front();
      q.pop();
      cout << t->name << " : " << t->score << endl;
      // 그 원소의 left와 right에 대해 NULL이 아니면 q에 넣는다.
      if (t->left != NULL) {
        q.push(t->left);
      }
      if (t->right != NULL) {
        q.push(t->right);
      }
    }
  }

  void copy_tree(MyTree &t1, MyTree t2) {
    t1.nodeCount = t2.nodeCount;
    t1.root = make_copy(t2.root);
  }
};

int main() { return 0; }