#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int roads[N - 1];
  int cities[N];

  for (int i = 0; i < N - 1; i++) {
    cin >> roads[i];
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> cities[i];
  }

  return 0;
}