# C review

#### random number 생성
```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));
rand() % 5  // 0~4까지 난수 생성
rand() % 5 +1 // 1~5까지 난수 생성
```