#include <iostream>
using namespace std;

void sub2(int a[]) {
  for (int i = 0; i < 5; i++) {
    a[i]++;
  }
}

int main() {
  int *p, *q, a, b;
  int arr[5] = {1, 3, 5, 7, 9};
  a = 3;
  b = 5;
  p = &a;
  q = &b;

  *p = *q;
  cout << a << endl;
  cout << b << endl;
  cout << *p << endl;
  cout << *q << endl;

  cout << endl;

  p = arr;
  q = arr;

  p += 3;
  *q += 3;
  cout << *p << endl;
  cout << *q << endl;

  int arr1[5] = {1, 3, 5, 7, 9};
  sub2(arr1);
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << endl;
  }
  p = arr1;

  p += 3;

  return 0;
}