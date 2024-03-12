#include <iostream>
using namespace std;

class weight
{
public:
  int kg, gram; // kg, gram 단위 멤버변수 선언
  void set_weight(int k, int g);
  int get_weight();
  weight add_weight(weight w1, weight w2);
};

void weight::set_weight(int k, int g)
{
  kg = k;
  gram = g;
}

int weight::get_weight()
{
  return kg * 1000 + gram;
}

weight add_weight(weight w1, weight w2)
{
  weight w3;
  int k, g;
  k = w1.kg + w2.kg;
  g = w1.gram + w2.gram;
  if (g >= 1000)
  {
    k += g / 1000;
    g = g % 1000;
  }
  w3.set_weight(k, g);
  return w3;
}

bool less_than(weight w1, weight w2)
{
  int gram1 = w1.kg * 1000 + w1.gram;
  int gram2 = w2.kg * 1000 + w2.gram;
  if (gram1 < gram2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  weight w1, w2, w3;
  w1.set_weight(3, 400);
  w2.set_weight(2, 700);
  w3 = add_weight(w1, w2);
  cout << w3.get_weight() << " grams\n";
  if (less_than(w1, w2))
  {
    cout << "yes.\n";
  }
  else
  {
    cout << "no.\n";
  }
}