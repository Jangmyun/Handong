#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  char x[50];
  cin >> N;
  char fileNames[N][50];

  for (int i = 0; i < N; i++)
  {
    cin >> fileNames[i];
  }

  if (N == 1)
  {
    cout << fileNames[0] << endl;
  }
  else
  {
    strcpy(x, fileNames[0]);
    cout << x << endl;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < sizeof(fileNames[0]) / sizeof(char); j++)
      {
        if (x[j] != fileNames[i][j])
        {
          x[j] = '?';
        }
      }
    }
  }
  cout << x << endl;
  return 0;
}
