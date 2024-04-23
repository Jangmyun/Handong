#include <iostream>
using namespace std;

int main() {
  int a[2][2] = {{1, 2}, {3, 4}};
  int b[4][10];

  int(*p)[10];

  p = b;

  return 0;
}