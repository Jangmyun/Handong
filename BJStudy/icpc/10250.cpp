#include <iostream>
using namespace std;

// 각 테스트 케이스에 대해
int eachTest(int h, int w, int n) {
  int f, r;  // 층, 호
  f = n % h;
  r = n / h + 1;

  return f * 100 + r;
}

int main() {
  int T, H, W, N;

  cin >> T;

  int arr[T];

  for (int i = 0; i < T; i++) {
    cin >> H >> W >> N;
    arr[i] = eachTest(H, W, N);
  }

  for (int s : arr) {
    cout << s << "\n";
  }

  return 0;
}