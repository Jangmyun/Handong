#include <iostream>
using namespace std;
#include <string>
#define SIZE 100
#define EOS '$'

class op_stack
{
  char s[SIZE];
  int top;

public:
  op_stack();
  void push(char x);
  char pop();
  bool empty();
  char top_element();
};

op_stack::op_stack()
{
  top = 0;
}

void op_stack::push(char x)
{
  s[top] = x;
  top++;
}

char op_stack::pop()
{
  top--;
  return (s[top]);
}

bool op_stack::empty()
{
  return (top == 0);
}

char op_stack::top_element()
{
  return (s[top - 1]);
}

bool is_operand(char ch)
{
  if ((65 <= ch <= 90) || (97 <= ch <= 122))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int get_precedence(char op)
{
  if ((op == '$') || (op == '('))
  {
    return 0;
  }
  else if ((op == '+') || (op == '-'))
  {
    return 1;
  }
  else if ((op == '*') || (op == '/'))
  {
    return 2;
  }
  else
  {
    return (-1);
  }
}

int main()
{
  string input, output;
  op_stack stack1;
  input += EOS;
  stack1.push(EOS);

  cout << "Input an infix expression to convert: ";
  cin >> input;

  for (int i = 0; i < input.size(); i++)
  {
  }

  return 0;
}
