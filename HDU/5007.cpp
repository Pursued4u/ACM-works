#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char s[100005];
char ap[6] = "Apple";
char ip2[5] = "iPad";
char ip1[7] = "iPhone";
char ip3[5] = "iPod";
char so[5]="Sony";
int main(){
    //freopen("in.txt","r",stdin);
    while(~scanf("%s",s)){
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='A'){
            char a[10];
            for(int j=0;j<5;j++){
                if(s[i+j]==' '||s[i+j]=='\n') break;
                a[j]=s[i+j];
            }
            a[5]='\0';
            //cout << a <<endl;
            if(!strcmp(a,ap))
            printf("MAI MAI MAI!\n");
        }
        else if(s[i]=='i'){
            char a[10];
            for(int j=0;j<4;j++){
                if(s[i+j]==' '||s[i+j]=='\n') break;
                a[j]= s[i+j];
            }
            a[4]='\0';
            //cout << a <<endl;
            if(!strcmp(a,ip2)||!strcmp(a,ip3)){
                printf("MAI MAI MAI!\n");
            }
            for(int j=0;j<6;j++){
                if(s[i+j]==' '||s[i+j]=='\n') break;
                a[j]=s[i+j];
            }
            a[6]='\0';
            //cout << a<<endl;
            if(!strcmp(a,ip1))
            printf("MAI MAI MAI!\n");
        }
        else if(s[i]=='S'){
            char b[5];
            for(int j=0;j<4;j++){
                //cout <<s[i+j] << endl;
                if(s[i+j]==' '||s[i+j]=='\n'||s[i+j]=='\0') break;
                b[j]=s[i+j];
            }
            b[4]='\0';
            if(!strcmp(b,so))
            printf("SONY DAFA IS GOOD!\n");
        }
    }
    }
}