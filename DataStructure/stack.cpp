#include <stdio.h>
using namespace std;

class mystack {
  int s[SIZE];
  int top;
  public:
    void init();
    void push(int x);
    int pop();
    bool stack_full();
    bool stack_empty();
};

int main(){
  
}