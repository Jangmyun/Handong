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
  s1.push(EOS);

  for (int i = 0; i < input.size(); i++) {
    if (isOperand(input[i])) {
      output += input[i];
    }
    if (input[i] == '(') {
      s1.push(input[i]);
    }
    if (input[i] == ')') {
      while (1) {
        char tmp;
        tmp = s1.pop();
        if (tmp == '(' || tmp == '$') {
          break;
        }
        output += tmp;
      }
    }
    if (!isOperand(input[i]) && input[i] != '(') {
      while (getPrecedence(input[i]) < getPrecedence(s1.topElement()) &&
             s1.topElement() != EOS) {
        output += s1.pop();
      }
      s1.push(input[i]);
    }
  }
  while (s1.empty()) {
    output += s1.pop();
  }
  cout << output << endl;
  return 0;
}