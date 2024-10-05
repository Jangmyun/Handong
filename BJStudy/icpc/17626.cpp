#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int n;

  cin >> n;

  // 최소 개수 1 개 부터 3개일 때 까지 하나씩 가능 값을 구하고
  // 3까지 없으면무조건 4임이 보장됨

  // 답이 1일 때 (square root 가 정수일 때)
  if (sqrt(n) - (int)sqrt(n) == 0) {
    cout << 1;
    return 0;
  }

  // 답이 2일 때
  return 0;
}