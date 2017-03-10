#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
    char a[10],b[10];
    char c[10],d[10];
int main()
{
    int i,n,j,flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s %s",a,b);
        printf("Case %d: ",i);
        if(a[0]==b[0])
            printf("= ");
        else if(a[0]>b[0])
            printf("> ");
        else printf("< ");
        int k=0;
        for(j=2;j<6;j++)
        {
            c[k]=a[j];
            d[k]=b[j];
            k++;
        }
        if(a[1]==b[1])
        {

            if(strcmp(c,d)<0)
                printf("<");
            else if(strcmp(c,d)==0)
                printf("=");
            else printf(">");
            printf("\n");
        }
        else
        {
            c[3]=d[3];
            if(strcmp(c,d)<0)
                printf("<");
            else if(strcmp(c,d)==0)
                printf("=");
            else printf(">");
            printf("\n");
        }
        }

}
