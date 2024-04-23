#include <iostream>
using namespace std;

int sum(int n) {  // 1부터 n까지 정수 합
  if (n == 0) return 0;
  return n + sum(n - 1);
}

int factorial(int n) {  // 팩토리얼
  if (n == 1) return 1;
  return n * factorial(n - 1);
}

int fibonacci(int n) {  // 피보나치 수열
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int evenSum(int n) {  // 1부터 n까지 짝수 합
  if (n == 1) return 0;
  if (n % 2 == 0) {
    return n + evenSum(n - 1);
  } else {
    return evenSum(n - 1);
  }
}

int arrSum(int arr[], int n) {  // 주어진 배열 앞쪽 n개 원소의 합
  if (n == 0) return 0;
  return arr[n - 1] + arrSum(arr, n - 1);
}

int permutation(int n, int m) {
  if (m == 0) return 1;
  return n * permutation(n - 1, m - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9};

  int a = arrSum(arr, 4);

  cout << a << endl;

  a = permutation(8, 4);
  cout << a << endl;
  return 0;
}