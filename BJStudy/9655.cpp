#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  string arr[] = {"CY", "SK"};

  cout << arr[N % 2];
  return 0;
}
