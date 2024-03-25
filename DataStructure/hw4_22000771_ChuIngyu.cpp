#include <iostream>
#include <string>
using namespace std;

class Palindrome_stack
{
  char s[100];
  int top;

public:
  Palindrome_stack();
  bool empty();
  char pop();
  void push(char c);
  char top_element();
};
Palindrome_stack::Palindrome_stack()
{
  top = 0;
}
bool Palindrome_stack::empty()
{
  return (top == 0);
}

void Palindrome_stack::push(char c)
{
  s[top] = c;
  top++;
}
char Palindrome_stack::pop()
{
  top--;
  return (s[top]);
}
char Palindrome_stack::top_element()
{
  return (s[top - 1]);
}

int main()
{
  string input;
  cout << "Input word: ";
  cin >> input;
}