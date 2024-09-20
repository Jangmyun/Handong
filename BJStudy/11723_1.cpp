#include <math.h>

#include <bitset>
#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int m;
  cin >> m;

  string input;
  int tmp;

  unsigned int a = 0;

  cout << noboolalpha;

  for (int i = 0; i < m; i++) {
    cin >> input;

    if (input == "all") {
      a &= ~(1 << 21);
    } else if (input == "empty") {
      a = 0;
    } else {
      cin >> tmp;
      unsigned int b = (1 << (tmp - 1));
      if (input == "add") {
        a |= b;
      }
      if (input == "remove") {
        a &= ~b;
      }
      if (input == "check") {
        cout << bool(a & b) << "\n";
      }
      if (input == "toggle") {
        a ^= b;
      }
    }
  }
  return 0;
}