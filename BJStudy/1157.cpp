#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int arr[26] = {0};
  cin >> input;

  if (input.length() == 1) {
    cout << char(toupper(input[0])) << endl;

    return 0;
  }

  arr[toupper(input[0]) - 65] += 1;
  int maxIndex = 0;
  int maxValue = 1;
  ;
  bool isDup = false;

  for (int i = 1; i < input.length(); i++) {
    int exactIndex = toupper(input[i]) - 65;
    arr[exactIndex] += 1;

    if (maxValue == arr[exactIndex]) {
      isDup = true;
    }
    if (maxValue < arr[exactIndex]) {
      isDup = false;
      maxValue = arr[exactIndex];
      maxIndex = exactIndex;
    }
  }

  if (isDup) {
    cout << "?" << endl;
  } else {
    cout << char(maxIndex + 65) << endl;
  }

  return 0;
}