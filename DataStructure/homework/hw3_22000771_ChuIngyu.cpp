#include <iostream>
#include <string>
using namespace std;

class bracket_stack
{
  char s[100];
  int top;

public:
  bracket_stack();
  void push(char c);
  char pop();
  bool empty();
  char top_element();
};

bracket_stack::bracket_stack()
{
  top = 0;
}
void bracket_stack::push(char c)
{
  s[top] = c;
  top++;
}

char bracket_stack::pop()
{
  top--;
  return (s[top]);
}

bool bracket_stack::empty()
{
  return (top == 0);
}

char bracket_stack::top_element()
{
  return (s[top - 1]);
}

bool isClosedBracket(char x)
{
  if (x == ')' || x == ']' || x == '}')
  {
    return true;
  }
  return false;
}
bool isOpenBracket(char x)
{
  if (x == '(' || x == '[' || x == '{')
  {
    return true;
  }
  return false;
}

int main()
{
  bracket_stack s;
  string input;
  string output;
  cout << "Input: ";
  getline(cin, input); // 공백 입력시 오류를 없애기 위해 getline 함수 사용
  bool errorChecker = false;

  for (int i = 0; i < input.length(); i++)
  {
    if (isOpenBracket(input[i])) // 여는 괄호일 때
    {
      s.push(input[i]); // stack에 push
    }
    else if (isClosedBracket(input[i])) // 닫는 괄호일 때
    {
      if (s.empty()) // 닫는 괄호가 나왔는데 스택은 비어있을 때 = 괄호의 짝이 안맞을 때
      {
        cout << "Error: An extra parenthesis \'" << input[i] << "\' is found." << endl;
      }

      char bracketChecker = s.pop();

      if (bracketChecker == '(' && input[i] != ')') // 스택에서 pop한 괄호와 닫는 괄호가 일치하지 않을경우 각 경우에 맞게 에러 메시지 출력
      {
        errorChecker = !errorChecker; // 에러가 발생했는지 여부 체크
        cout << "Error: mis-matched parenthesis, ')' is expected." << endl;
        return 0;
      }
      if (bracketChecker == '{' && input[i] != '}')
      {
        errorChecker = !errorChecker;
        cout << "Error: mis-matched parenthesis, '}' is expected." << endl;
        return 0;
      }
      if (bracketChecker == '[' && input[i] != ']')
      {
        errorChecker = !errorChecker;
        cout << "Error: mis-matched parenthesis, ']' is expected." << endl;
        return 0;
      }
    }
  }
  if (!s.empty() && errorChecker) //  스택내부에 아직 남은 원소가 있을경우 && 위 반복문에서 에러가 발생하지 않은 경우
  {
    cout << "Error: Extra open bracket is left." << endl;
    return 0;
  }
  else if (s.empty() && !errorChecker) // 정상적인 수식일 때
  {
    cout << "It's a normal expression";
    return 0;
  }
}