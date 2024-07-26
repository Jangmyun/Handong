#include <iostream>
#include <string>
using namespace std;

#define SIZE 100
#define EOS '$'

class op_stack {
  char s[SIZE];
  int top;

 public:
  op_stack();
  void push(char x);
  char pop();
  bool empty();
  char top_element();
};

op_stack::op_stack() { top = 0; }
void op_stack::push(char x) {
  s[top] = x;
  top++;
}
char op_stack::pop() {
  top--;
  return (s[top]);
}
bool op_stack::empty() { return (top == 0); }
char op_stack::top_element() { return (s[top - 1]); }

bool isOperand(char ch) {
  if ((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') ||
      (ch == '/') || (ch == '%') || (ch == '$')) {
    return false;
  } else {
    return true;
  }
}

int get_precedence(char op) {
  if ((op == '$') || (op == '(')) {
    return 0;
  }
  if ((op == '+') || (op == '-')) {
    return 1;
  }
  if ((op == '*') || (op == '/') || (op == '%')) {
    return 2;
  }
  return -1;
}

int main() {
  string input, output;

  op_stack stack1;
  cout << "Input an infix expression to convert: ";
  cin >> input;
  input += EOS;
  stack1.push(EOS);

  for (int i = 0; i < input.length(); i++)  // input 길이만큼 반복
  {
    if (isOperand(input[i]))  // 피연산자면 바로 출력
    {
      output += input[i];
    }
    if (input[i] == '(')  // '(' 라면 stack에 넣기
    {
      stack1.push(input[i]);
    }
    if (input[i] == ')')  // ')' 라면 '(' 나올 때 까지 pop 하고 '(' 제거
    {
      while (stack1.top_element() != '(' && stack1.top_element() != '$') {
        output += stack1.pop();
      }
      stack1.pop();
    }
    if (!isOperand(input[i]) &&
        input[i] != '(')  // 연산자라면 stack top 원소의 precedence가 토큰의
                          // precedence 보다 낮아질 때까지 pop
    {
      while (get_precedence(input[i]) < get_precedence(stack1.top_element()) &&
             stack1.top_element() != '$') {
        output += stack1.pop();
      }
      stack1.push(input[i]);  // pop 끝난 후 토큰을 push
    }
  }
  while (stack1.empty())  // 남은 원소를 모두 pop
  {
    output += stack1.pop();
  }
  cout << output << endl;  // 결과값 출력
}