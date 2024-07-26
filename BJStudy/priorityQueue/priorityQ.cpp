#include <functional>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int> > pq;

  pq.push(5);
  pq.push(4);
  pq.push(500);

  cout << pq.top() << endl;

  return 0;
}