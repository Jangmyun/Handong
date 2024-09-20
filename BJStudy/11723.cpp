#include <iostream>
#include <set>
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  set<int> s;
  int m;

  cin >> m;

  string input;
  int tmp;

  for (int i = 0; i < m; i++) {
    cin >> input;

    if (input == "all") {
      for (int j = 1; j < 21; j++) {
        s.insert(j);
      }
    } else if (input == "empty") {
      s.clear();
    } else {
      cin >> tmp;
      if (input == "add") {
        s.insert(tmp);
      }
      if (input == "remove") {
        s.erase(tmp);
      }
      if (input == "check") {
        if (s.find(tmp) == s.end()) {
          cout << 0 << "\n";
        } else {
          cout << 1 << "\n";
        }
      }
      if (input == "toggle") {
        if (s.find(tmp) == s.end()) {
          s.insert(tmp);
        } else {
          s.erase(tmp);
        }
      }
    }
  }

  return 0;
}
