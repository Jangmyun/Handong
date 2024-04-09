public class Rep04Riddler1 {
  public static void main(String[] args) {

    for (int i = 0; i < 10; i++) { // 천의 자리
      for (int j = 0; j < 10; j++) { // 백의 자리
        for (int k = 0; k < 10; k++) { // 십의 자리
          for (int l = 0; l < 10; l++) { // 일의 자리
            if (i != j && j != k && k != l && i != k && i != l && j != l) { // 각 자리 숫자가 모두 다를 때 출력
              System.out.printf("The address is %d %d %d %d on Lake Otis Parkway.\n", i, j, k, l);
            }
          }
        }
      }
    }
  }
}
