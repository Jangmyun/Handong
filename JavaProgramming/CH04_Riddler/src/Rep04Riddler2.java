public class Rep04Riddler2 {
  public static void main(String[] args) {
    for (int i = 0; i < 10; i++) { // 천의 자리
      for (int j = 0; j < 10; j++) { // 백의 자리
        for (int k = 0; k < 10; k++) { // 십의 자리
          for (int l = 0; l < 10; l++) { // 일의 자리
            int address = i * 1000 + j * 100 + k * 10 + l; // 각 자릿수에 맞게 address 선언
            if (i != j && j != k && k != l && i != k && i != l && j != l) { // 각 자리 숫자가 모두 다르면서
              if (i == k * 3 && address % 2 != 0) { // 천의 자리가 십의 자릿수의 3배이고 address를 2로 나누었을 때 나머지가 0이 아닐 때 (홀수일 때)
                System.out.printf("The address is %d %d %d %d on Lake Otis Parkway.\n", i, j, k, l);
              }
            }
          }
        }
      }
    }
  }
}
