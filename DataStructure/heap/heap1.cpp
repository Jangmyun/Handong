#include <iostream>
using namespace std;
#define HSIZE 100

class element {
 public:
  string name;
  double score;
  void set_data(string n, double s) {
    name = n;
    score = s;
  }
};

class myheap {
  element h[HSIZE];
  int csize;

 public:
  myheap();
  myheap(element a[], int n);
  int h_size();
  void insert_heap(element t);
  element delete_heap();
  bool heap_full();
  bool heap_empty();
  void adjust(int t_root);
};
myheap::myheap() { csize = 0; }

bool myheap::heap_empty() {
  if (csize == 0) return true;
  return false;
}

bool myheap::heap_full() {
  if (csize >= HSIZE - 1) return true;
  return false;
}

int myheap::h_size() { return csize; }

void myheap::insert_heap(element t) {
  int k;
  csize++;
  // csize 1증가
  k = csize;
  // parent 값이 주어진 값 보다 작으면
  while ((k != 1) && (t.score > h[k / 2].score)) {
    // parent 값을 현위치로 이동
    h[k] = h[k / 2];
    // parent로 위치 이동
    k /= 2;
  }
  // 최종 찾은 위치에 값 넣기
  h[k] = t;
}

element myheap::delete_heap() {
  element t;
  element tmp;
  int parent, child;

  t = h[1];        // return할 root값 저장
  tmp = h[csize];  // 끝원소 저장
  csize--;
  parent = 1;  // root
  child = 2;   // root의 left

  // root 부터 아래쪽으로 반복
  while (child <= csize) {
    // left 와 right 비교해서 더 큰값 선택
    if ((child < csize) && (h[child].score < h[child + 1].score)) {
      child++;
    }
    // 해당 원소의 값보다 child가 작으면 parent위치로 결정
    if (tmp.score >= h[child].score) break;
    h[parent] = h[child];
    parent = child;
    child *= 2;
  }
  h[parent] = tmp;
  return t;
}

// root의 위치만 잘못된 tree에 대하여 root 위치를 재조정
void myheap::adjust(int t_root) {
  double tmpkey;
  int child;
  element tmp;

  tmp = h[t_root];  // root 저장
  tmpkey = h[t_root].score;
  child = 2 * t_root;  // left를 child로

  while (child <= csize) {
    if ((child < csize) && (h[child].score < h[child + 1].score)) {
      child++;
    }
    if (tmpkey > h[child].score) {
      break;
    } else {
      h[child / 2] = h[child];
      child *= 2;
    }
  }
  h[child / 2] = tmp;
}

myheap::myheap(element a[], int n) {
  int k;

  for (k = 1; k <= n; k++) {
    h[k] = a[k - 1];
  }
  csize = n;

  for (k = n / 2; k >= 1; k--) {
    adjust(k);
  }
}

int main() {
  myheap h1;

  element temp;
  temp.set_data("Kim", 88);
  h1.insert_heap(temp);
  temp.set_data("Lee", 77);
  h1.insert_heap(temp);
  temp.set_data("Park", 98);
  h1.insert_heap(temp);
  temp.set_data("Choi", 74);
  h1.insert_heap(temp);
  temp.set_data("Ryu", 94);
  h1.insert_heap(temp);
  temp.set_data("Cho", 85);
  h1.insert_heap(temp);
  while (h1.h_size() > 0) {
    temp = h1.delete_heap();
    cout << temp.name << " : " << temp.score << "\n";
  }
  return 0;
}