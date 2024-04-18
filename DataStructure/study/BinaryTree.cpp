#include <iostream>
using namespace std;

// Binary tree 의 연산에 대한 구현이며, 총 4문항입니다. 강의에서 예를 들었던,
// inorder-traversal과 같이 recursive function으로 구현하는 내용과, 지난시간에
// 강의 하였던 level order traversal algorithm을 사전에 공부

class node {
 public:
  string name;
  double score;
  node *left, *right;
  void set_data(string s, double n);
};

class my_stack {
  node *s[100];
  int top;

 public:
  my_stack() { top = 0; }
  void push(node *t) {
    s[top] = t;
    top++;
  }
  node *pop() {
    top--;
    return s[top];
  }
  bool empty() {
    if (top == 0) {
      return true;
    }
    return false;
  }
  node *top_element() { return s[top - 1]; }
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

void node::set_data(string s, double n) {
  name = s;
  score = n;
}

class my_tree {
 public:
  int node_count;                         // 현재 node 수
  node *root;                             // root를 가리키는 pointer
  my_tree();                              // 초기화
  int insert_root(node t);                // root로 node내용 t추가
  int insert_left(string tname, node t);  // tname의 node 왼쪽에 t 추가
  int insert_right(string tname, node t);

  double score_sum();
  double score_average();
  void print_data_inorder();
  void print_data_preorder();
  void print_data_postorder();
  void print_data_levelorder() {
    my_queue a1;  // node pointer 저장하는 q생성
    node *t;
    if (root == NULL) {  // root NULL 이면 return
      return;
    }
    // root NULL 아니면
    a1.insert_q(root);  // q에 root 넣고 아래 코드 반복
    while (1) {
      if (a1.queue_empty()) {  // q 비었으면 종료
        return;
      }
      t = a1.delete_q();  // q로부터 하나 원소 가져오기
      cout << t->name << " : " << t->score << endl;  // 가져온 원소 출력
      if (t->left != NULL) {  // 가져온 원소의 left와 right 큐에 넣기
        a1.insert_q(t->left);
      }
      if (t->right != NULL) {
        a1.insert_q(t->right);
      }
    }
  }
};

my_tree::my_tree() {
  node_count = 0;
  root = NULL;
}

int my_tree::insert_root(node t) {
  if (root != NULL) {  // root가 NULL이 아니면 실패 0리턴
    return 0;
  }

  node *p;
  p = new node;    // node 메모리 할당
  *p = t;          // node 내용 카피
  p->left = NULL;  // left right NULL 설정
  p->right = NULL;
  root = p;  // root에 node주소값
  return 1;
}

int node_insert_left(node *p, string tname, node tnode) {
  // 1: insert 성공 // 0: tname 노드가 없음 // -1: tname노드 있는데 NULL아님
  if (p == NULL) {  // p가 NULL이면 0리턴
    return 0;
  }
  if (p->name == tname) {   // tname 노드 있음
    if (p->left != NULL) {  // tname 노드 있는데 NULL 아니면 -1리턴
      return -1;
    }
    // tname 노드 있고 NULL 이면
    node *t;
    t = new node;    // 메모리 할당
    *t = tnode;      // data 복사
    t->left = NULL;  // left right NULL로
    t->right = NULL;
    p->left = t;  // p의 left에 t연결
    return 1;
  } else {  // root가 찾는 tname이 아니면 left 에서 같은 작업 수행
    int result = node_insert_left(p->left, tname, tnode);
    if (result != 0) {  // root의 결과가 0이 아니면 (노드 못찾은 경우 아니면 )
      return result;  // 그대로 result 리턴
    }
    return node_insert_left(
        p->right, tname,
        tnode);  // 노드 아직 못찾았으면 right에서 같은 작업 수행하고 결과 리턴
  }
}

int my_tree::insert_left(string tname, node t) {
  // 1: insert 성공 // 0: tname 노드가 없음 // -1: tname노드 있는데 NULL아님
  int result = node_insert_left(root, tname, t);
  if (result == 1) {
    node_count++;
  }
  return result;
}

int node_insert_right(node *p, string tname, node tnode) {
  if (p == NULL) {
    return 0;
  }
  if (p->name == tname) {
    if (p->right != NULL) {
      return -1;
    }

    node *t;
    t = new node;
    *t = tnode;
    t->left = NULL;
    t->right = NULL;

    p->right = t;
    return 1;
  } else {
    int result = node_insert_right(p->left, tname, tnode);
    if (result != 0) {
      return result;
    }
    return node_insert_right(p->right, tname, tnode);
  }
}

int my_tree::insert_right(string tname, node t) {
  // 1: insert 성공 // 0: tname 노드가 없음 // -1: tname노드 있는데 NULL아님
  int result = node_insert_right(root, tname, t);
  if (result == 1) {
    node_count++;
  }
  return result;
}

double sum_allNodes(node *p) {
  if (p == NULL) {  // root NULL이면 0리턴
    return 0;
  }
  // left subtree의 모든 노드 값 합 + right 값합 + 현재 노드 값
  return sum_allNodes(p->left) + sum_allNodes(p->right) + p->score;
}

double my_tree::score_sum() { return sum_allNodes(root); }

double my_tree::score_average() { return score_sum() / node_count; }

void inorder_print(node *p) {
  if (p == NULL) {
    return;
  }

  inorder_print(p->left);
  cout << p->name << " : " << p->score << endl;
  inorder_print(p->right);
}

void my_tree::print_data_inorder() { inorder_print(root); }

int main() {
  my_tree theTree;
  node tmp;
  tmp.set_data("Kim", 8.1);
  theTree.insert_root(tmp);
  tmp.set_data("Lee", 6.5);
  theTree.insert_left("Kim", tmp);
  tmp.set_data("Park", 8.3);
  theTree.insert_right("Kim", tmp);
  tmp.set_data("Choi", 7.2);
  theTree.insert_left("Lee", tmp);
  tmp.set_data("Ryu", 9.0);
  theTree.insert_right("Lee", tmp);
  tmp.set_data("Cho", 7.7);
  theTree.insert_right("Park", tmp);
  cout << "Score Sum : " << theTree.score_sum() << "\n";
  cout << "Score Average : " << theTree.score_average() << "\n";
  cout << "\n Inorder Traversal Result \n";
  theTree.print_data_inorder();
  // cout << "\n Preorder Traversal Result \n";
  // theTree.print_data_preorder();
  // cout << "\n Postorder Traversal Result \n";
  // theTree.print_data_postorder();
  cout << endl;
  theTree.print_data_levelorder();
  return 0;
}