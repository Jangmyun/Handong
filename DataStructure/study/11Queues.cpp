#include <iostream>
using namespace std;
#define Q_SIZE 100

class queue
{
  int q[Q_SIZE];
  int front, rear;

public:
  queue();
  void insert_q(int x);
  int delete_q();
  bool queue_full();
  bool queue_empty();
};
queue::queue()
{
  front = 0;
  rear = 0;
}
void queue::insert_q(int x)
{
  if (!queue_full())
  {
    q[rear] = x;
    rear = (rear + 1) % Q_SIZE;
  }
}

int queue::delete_q()
{
  int tmp;
  if (!queue_empty())
  {
    tmp = q[front];
    front = (front + 1) % Q_SIZE;
    return (tmp);
  }
}

bool queue::queue_full()
{
  if ((rear + 1) % Q_SIZE == front)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool queue::queue_empty()
{
  if (rear == front)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  // Queue 연산 > Create Queue , Insert, Delete, Full test, Empty test
  return 0;
}