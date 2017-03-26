#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int main()
{
  int M;
  int a[17];
  char b[17] = {'#','p','q','r','u','v','w','x','y','z'};
  scanf("%d",&M);
  getchar();
  while(M--)
  {
    for(int k = 1; k <= 10; k++)
    {
      scanf("%d",&a[k]);
    }
    int cont = 0;
    int flag = 0;
    for(int k = 1; k < 10; k++)
    {
      if(a[k]==0)
        continue;
      cont++;
      if(cont == 1)
      {
        if(a[k] != 1 && a[k] != -1)
          printf("%d%c",a[k],b[k]);
        else if(a[k] == 1)
          printf("%c",b[k]);
        else if(a[k] == -1)
          printf("-%c",b[k]);
        flag = 1;
      }
      else
      {
        if(a[k] > 0)
          printf("+");
        if(a[k] != 1 && a[k] != -1)
          printf("%d%c",a[k],b[k]);
        else if(a[k] == 1)
          printf("%c",b[k]);
        else if(a[k] == -1)
          printf("-%c",b[k]);
        flag = 1;
      }
    }
    if(a[10])
    {
      if(a[10] > 0 && flag)
        printf("+");
      printf("%d",a[10]);
      flag = 1;
    }
    if(!flag)//Ã»ÓÐ´ð°¸
      printf("0");
    printf("\n");
  }
  return 0;
}
