# C review

#### random number 생성
```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));  // 
rand() % 5  // 0~4까지 난수 생성
rand() % 5 +1 // 1~5까지 난수 생성
```

#### File 읽기 쓰기

```c
FILE *file;
int count = 0;

file = fopen("filename.txt", "r"); 
while(!feof(file)){
  int r = fscanf(file, "%d %s %d",);
  if( r<4){
    break;
  }
  count ++;
}
fprintf(file,"%d %d" , a,b);

fclose(file);
// 읽기=r 쓰기=w 더하기=a 
```

#### 메모리 동적 할당
```c
#include <stdlib.h>

int *a;
a= (int*)malloc(sizeof(int)*4); 
// int타입 4개 만큼의 메모리 할당
free(a) // 동적할당 해제
```

#### 라이브러리
##### 정적 라이브러리
1. 헤더파일 생성 (*.h)
2. 라이브러리에 포함되는 함수 코드 구현 (*.c)
3. 라이브러리 컴파일 (*.o)
4. 정적라이브러리 생성 (*.a)
5. Object파일을 사용한 컴파일/실행 (Object파일의 모든 코드 포함)
6. 정적라이브러리 이용한 컴파일/실행 (필요한 코드만 포함)

```bash
$gcc -c calculator.c
$ar rv libcal.a calculator.o
$gcc ca
```


