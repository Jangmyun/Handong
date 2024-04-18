#include <iostream>
#include <string>

//  An ordered list using linked list
//  Practice in class

using namespace std;

class node
{
public:
  string name;
  double score;
  node *link;
  void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
  name = s;
  score = n;
}

class my_list
{
  node *head;

public:
  my_list()
  {
    head = NULL;
  }
  void insert_node(node t);
  void show_all_data();
};

void my_list::insert_node(node t) // score값을 기준으로 sorted된 위치에 node t를 삽입하는 함수
{
  node *tmp;

  tmp = new node;
  (*tmp) = t;

  if (head == NULL)
  {
    head = tmp;
    head->link = NULL;
    return;
  }
  if (head->score > tmp->score)
  {
    tmp->link = head;
    head = tmp;
    return;
  }
  node *i;
  node *next;
  for (i = head; i != NULL; i = i->link)
  {
    next = i->link;
    if (!(next != NULL && next->score < tmp->score))
    {
      break;
    }
  }
  if (i == NULL)
  {
    i->link = tmp;
  }
  else
  {
    i->link = tmp;
    tmp->link = next;
  }
}

void my_list::show_all_data()
{
  node *p;

  for (p = head; p != NULL; p = p->link)
    cout << p->name << " : " << p->score << endl;
}

int main()
{
  my_list thelist;
  node tmp;
  tmp.set_data("Kim", 73.5);
  thelist.insert_node(tmp);
  tmp.set_data("Lee", 82.2);
  thelist.insert_node(tmp);
  tmp.set_data("Park", 51.3);
  thelist.insert_node(tmp);
  tmp.set_data("Choi", 95.1);
  thelist.insert_node(tmp);
  tmp.set_data("Ryu", 71.3);
  thelist.insert_node(tmp);
  tmp.set_data("Yang", 58.2);
  thelist.insert_node(tmp);
  tmp.set_data("Hong", 83.5);
  thelist.insert_node(tmp);

  cout << "-- The list after insertions \n";
  thelist.show_all_data();

  return 0;
}
