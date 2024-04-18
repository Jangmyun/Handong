#include <iostream>
#include <string>
using namespace std;
#define YES true
#define No false

bool check(string input, int indexStart, int indexEnd);

int main()
{
  string input;
  int len;
  cout << "Input a string: ";
  cin >> input;
  len = input.size();
  if (check(input, 0, len - 1) == YES)
  {
    cout << "Yes, it is a palindrome.\n";
  }
  else
  {
    cout << "No, it is not a palindrome.\n";
  }
  return 0;
}

bool check(string input, int indexStart, int indexEnd) // palindrome 체크 함수 , 파라미터로 문자열, 비교할 두 인덱스를 받음
{
  if (indexStart >= indexEnd) // 함수가 재귀적으로 호출되다가 더이상 비교할 인덱스가 남아있지 않을 경우 true
  {
    return true;
  }

  if (input[indexStart] != input[indexEnd]) // 비교한 문자가 같지 않을 경우 false
  {
    return false;
  }

  return check(input, indexStart + 1, indexEnd - 1); // 비교한 문자가 같을 경우 다음 인덱스로 check 함수 호출
}
