#include <iostream>
#include <string>
using namespace std;

string reverse(string input); // 문자열을 매개변수로 받는 reverse함수 선언

int main()
{
  string input, r_input; // 과제 템플릿
  cout << "Input a string: ";
  cin >> input;
  r_input = reverse(input);
  cout << r_input << endl;
  return 0;
}

string reverse(string input) // 함수 구현부
{
  string output;                      // 빈 문자열 생성
  int lastIndex = input.length() - 1; // 매개변수로 전달받은 문자열의 마지막 인덱스 번호

  if (input.length() <= 1) // 문자열이 하나 남았을 때는 해당 문자열만 전달
  {
    return input;
  }
  else
  {
    output += input[lastIndex];       // output에 문자열의 마지막 문자를 넣음
    input.erase(lastIndex, 1);        // 마지막 문자열을 지움
    return (output + reverse(input)); // 지워진 문자열을 다시 reverse함수에 전달하고 그 값을 output에 넣음 (reverse에 전달받은 문자열이 1일때까지 재귀적으로 호출됨)
  }
}