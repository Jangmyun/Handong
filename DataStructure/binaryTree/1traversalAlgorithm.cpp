#include <iostream>
using namespace std;

class node {
  string name;
  double score;
  node *left, *right;

 public:
  string getName() { return this->name; }
  double getScore() { return this->score; }
};

int main() { return 0; }