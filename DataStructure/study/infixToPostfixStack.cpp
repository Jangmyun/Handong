#include <iostream>
using namespace std;
#define EOS '$'

class op_stack {
 public:
  int top;
  char s[100];

  op_stack() { top = 0; };
  void push(char op) {
    s[top] = op;
    top++;
  }
  char pop() {
    top--;
    return s[top];
  }
  char topElement() { return s[top - 1]; }
  bool full() {
    if (top == 99) {
      return true;
    } else {
      return false;
    }
  }
  bool empty() {
    if (top == 0) {
      return true;
    } else {
      return false;
    }
  }
};

bool isOperand(char c) {
  if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' ||
      c == '%' || c == '$') {
    return false;
  }
  return true;
}

int getPrecedence(char c) {
  if (c == '$' || c == '(') {
    return 0;
  }
  if (c == '+' || c == '-') {
    return 1;
  }
  if (c == '*' || c == '/' || c == '%') {
    return 2;
  }
  return -1;
}

int main() {
  string input, output;
  cin >> input;
  op_stack s1;

  for (int i = 0; i < input.size(); i++) {
    char c = input[i];
    if (isOperand(c)) {  // 피연산자면 바로 출력
      output += c;
    } else if (c == '(') {  // '(' 면 스택에 push
      s1.push(c);
    } else if (c == ')') {
      while (s1.topElement() != '(') {  // '(' 나올때까지 pop하여 output에 추가
        output += s1.pop();
      }
      s1.pop();  // 스택에서 '(' 삭제
    } else {     // 연산자라면
      while (!s1.empty() && getPrecedence(c) < getPrecedence(s1.topElement())) {
        output += s1.pop();
      }
      s1.push(c);
    }
  }
  while (!s1.empty()) output += s1.pop();

  cout << output << endl;

  return 0;
}
