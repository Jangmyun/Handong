#include <iostream>
#include <string>
using namespace std;

#define EOS '$'

class node
{
public:
  char op;
  node *link;
  void set_data(char c);
};
void node::set_data(char c)
{
  op = c;
}

class op_stack
{
  node *top;

public:
  op_stack();
  void push(node t);
  node pop();
  bool stack_empty();
  node top_element();
};

op_stack::op_stack()
{
  top = NULL;
}

void op_stack::push(node t)
{
  node *p;
  p = new node;
  (*p) = t;
  p->link = NULL;

  if (top == NULL)
  {
    top = p;
    return;
  }
  p->link = top;
  top = p;
}

node op_stack::pop()
{
  node tmp;
  node *t;
  t = top;
  tmp = *top;
  top = top->link;
  delete t;

  return tmp;
}
bool op_stack::stack_empty()
{
  if (top == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
// a*(b+c)–d/e
node op_stack::top_element()
{
  return *top;
}

bool isOperand(char ch)
{
  if ((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '$'))
  {
    return false;
  }
  else
  {
    return true;
  }
}
int get_precedence(char op)
{
  if ((op == '$') || (op == '('))
  {
    return 0;
  }
  if ((op == '+') || (op == '-'))
  {
    return 1;
  }
  if ((op == '*') || (op == '/') || (op == '%'))
  {
    return 2;
  }
  return -1;
}

int main()
{
  string input, output;
  node tmp;
  op_stack stack1;
  cout << "Input an infix expression to convert: ";
  cin >> input;
  input += EOS;

  tmp.set_data(EOS);
  stack1.push(tmp);

  for (int i = 0; i < input.length(); i++) // input 길이만큼 반복
  {
    if (isOperand(input[i])) // 피연산자면 바로 출력
    {
      output += input[i];
    }
    if (input[i] == '(') // '(' 라면 stack에 넣기
    {
      tmp.set_data(input[i]);
      stack1.push(tmp);
    }
    if (input[i] == ')') // ')' 라면 '(' 나올 때 까지 pop 하고 '(' 제거
    {
      while ((stack1.top_element()).op != '(' && (stack1.top_element()).op != EOS)
      {
        tmp = stack1.pop();
        output += tmp.op;
      }
      stack1.pop();
    }
    if (!isOperand(input[i]) && input[i] != '(') // 연산자라면 stack top 원소의 precedence가 토큰의 precedence 보다 낮아질 때까지 pop
    {
      while (get_precedence(input[i]) < get_precedence((stack1.top_element()).op) && (stack1.top_element()).op != EOS)
      {
        tmp = stack1.pop();
        output += tmp.op;
      }
      tmp.set_data(input[i]);
      stack1.push(tmp); // pop 끝난 후 토큰을 push
    }
  }
  while (stack1.stack_empty()) // 남은 원소를 모두 pop
  {
    tmp = stack1.pop();
    output += tmp.op;
  }
  cout << output << endl; // 결과값 출력
  return 0;
}