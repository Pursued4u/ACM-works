#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int a[100000005];

int main(){
    int t,s;
    scanf("%d",&t);
    for(s=1;s<=t;s++)
    {
    int n;
    cin>>n;
    a[0]=1;
    int k=1;
    int temp;
    int carry=0;
    int i;
    int j;
    for(i=0;i<n;i++){
        carry=0;
        for(j=0;j<k;j++){
            temp=a[j]*32+carry;
            a[j]=temp%10;
            carry=temp/10;
        }
        if(carry!=0)
            a[k++]=carry;
    }
    printf("Case #%d: ",s);
    for(i=k-1;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
    }
}
