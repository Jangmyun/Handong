#include <iostream>
using namespace std;

class node // 데이터 저장될 노드 클래스
{
public:
  string name;
  double score;
  node *link;                        // 다음 노드의 주소
  void set_data(string s, double n); // 데이터 initializing 함수
};
void node::set_data(string s, double n)
{
  name = s;
  score = n;
}

class my_list // linked list 클래스
{
  node *head, *tail; // 처음과 끝부분 node의 주소

public:
  my_list();
  void add_to_head(node t);
  void add_to_tail(node t);
  node delete_from_head();
  int num_nodes();
  bool list_empty();
  double score_sum();
  double get_score(string t_name);
  int remove_a_node(string t_name);
};
my_list::my_list() // constructor
{
  head = NULL;
  tail = NULL;
}
void my_list::add_to_head(node t)
{
  node *p;          // node 타입 포인터 변수 p 선언
  p = new node;     // 메모리 할당
  (*p) = t;         // p주소에 있는 값 = 매개변수로 받은 t
  p->link = head;   // p가 가리키는 값은 head
  head = p;         // head의 주소값 = p;
  if (tail == NULL) // empty였을 경우 tail = p
  {
    tail = p;
  }
}

void my_list::add_to_tail(node t)
{
  node *p;
  p = new node;
  (*p) = t;
  p->link = NULL;   // p가 가리키는 주소 = NULL
  if (tail != NULL) // empty가 아니라면 tail이 가리키는 주소값 = p
  {
    tail->link = p;
  }
  else // empty라면 head도 변경
  {
    head = p;
  }
  tail = p; //
}

node my_list::delete_from_head()
{
  node tmp; // 삭제한 head의 값을 저장했다가 return
  node *t;
  t = head;          // 포인터 변수 t에 head 주소값 저장
  tmp = *head;       // tmp에 head값 저장
  head = head->link; // head= head가 가리키는 주소값으로 지정
  delete t;          // t가 가리키는 주소의 메모리 해제
  if (head == NULL)  // t 삭제 후 empty라면 tail도 NULL
  {
    tail = NULL;
  }
  return tmp; // tmp return
}

int my_list::num_nodes()
{
  node *t;
  int count = 0;
  for (t = head; t != NULL; t = t->link)
  {
    count++;
  }
  return count;
}

bool my_list::list_empty() // empty check
{
  if (head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

double my_list::score_sum() // score 더하기
{
  double sum = 0.0; // return할 sum
  node *i;
  for (i = head; i != NULL; i = i->link)
  {
    sum += i->score;
  }
  return sum;
}
double my_list::get_score(string t_name)
{
  node *i;
  for (i = head; i != NULL; i = i->link)
  {
    if (i->name == t_name) // 반복중인 node의 name과  t_name가 같으면 해당 node score리턴
    {
      return i->score;
    }
  }
  return -1;
}

int my_list::remove_a_node(string t_name)
{
  node *i;                                       // 노드 반복
  node *current;                                 // 현노드
  node *prev;                                    // 이전노드
  for (i = head; i->name != t_name; i = i->link) // head부터 i->name이 t_name이 아닌동안 반복
  {
    prev = i;          // 현재 반복중이 node가 이전노드가 되고
    current = i->link; // i의 다음 원소가 현재노드
  }
  if (current == head) // 현재노드가 head라면
  {
    head = head->link; // head는 head의 다음 원소르 가리키고
    delete i;          // i는 제거
    return 1;
  }
  if (current == NULL)
  {
    return 0;
  }

  prev->link = i->link;
  delete i;
  return 1;
}

int main()
{
  my_list a;
  node tmp;

  tmp.set_data("Kim", 83.5);
  a.add_to_head(tmp);
  tmp.set_data("Lee", 78.2);
  a.add_to_head(tmp);
  cout << a.num_nodes() << " : " << a.score_sum() << endl;
  tmp.set_data("Park", 91.3);
  a.add_to_tail(tmp);
  cout << a.num_nodes() << " : " << a.score_sum() << endl;
  tmp = a.delete_from_head();
  cout << tmp.name << " is deleted.\n";
  tmp.set_data("Choi", 85.1);
  a.add_to_tail(tmp);
  tmp.set_data("Ryu", 94.3);
  a.add_to_head(tmp);
  cout << a.num_nodes() << " : " << a.score_sum() << endl;
  cout << "Parks score : " << a.get_score("Park") << endl;
  if (a.remove_a_node("Kim") == 1)
  {
    cout << "Kim is deleted from the list. \n";
  }
  cout << a.num_nodes() << " : " << a.score_sum() << endl;
}