#include <iostream>
using namespace std;

class weight // weight 클래스 선언
{
private:        // 멤버 데이터 private으로 선언
  int kg, gram; // kg, gram 단위 멤버변수 선언
public:         // private data에 접근하기 위해 메서드는 public으로 선언
  void set_weight(int k, int g);
  int get_weight();
  weight add_weight(weight w1, weight w2);
  int getKg();
  int getGram();
};

// private 변수인 kg, gram에 접근하기위한 함수 getKg, getGram
int weight::getKg()
{
  return kg;
}
int weight::getGram()
{
  return gram;
}

// kg과 gram 정수를 입력받아 멤버변수 값 갱신하는 함수
void weight::set_weight(int k, int g)
{
  kg = k;
  gram = g;
}

// kg, g으로 저장된 값을 gram단위로 합쳐서 리턴하는 함수
int weight::get_weight()
{
  return kg * 1000 + gram;
}

// weight 객체 두개를 매개변수로 받아 두 값을 더한 새로운 객체를 리턴하는 함수
weight add_weight(weight w1, weight w2)
{
  weight w3; // 객체 생성
  int k, g;
  // getKg, getGram 메서드를 사용해서 kg, gram에 접근
  k = w1.getKg() + w2.getKg();
  g = w1.getGram() + w2.getGram();
  if (g >= 1000) // gram이 1000 넘을 때 kg으로 단위 넘기기
  {
    k += g / 1000;
    g = g % 1000;
  }
  w3.set_weight(k, g);
  return w3;
}

// 어떤 쪽의 무게가 더 큰지 비교하는 일반함수
bool less_than(weight w1, weight w2)
{
  int gram1 = w1.getKg() * 1000 + w1.getGram();
  int gram2 = w2.getKg() * 1000 + w2.getGram();
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