#include<bits/stdc++.h>
using namespace std;
string a[55];
string sub(string str1,string str2)//高精度减法
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}
int main()
{
    int t;
    scanf("%d",&t);
    int ca=1;
    int p=0;
    while(t--)
    {

        p=0;
        int flag=0;
        string s;
        cin >> s;
        printf("Case #%d:\n",ca++);
        string b;
        while(1)
        {
            if(s=="20")
            {

                a[p++]="11";
                s="9";
                continue;
            }
            b="";
            if(s=="")
            s="0";
            int len=s.length();
            if(len==1)
            break;
            if(s[0]=='1')
                flag=1;
            for(int i=1;i<len;i++)
            {
                if(s[i]!='0')
                flag=0;
            }
            if(flag)
            {
                for(int i=0;i<len-1;i++)
                b+='9';
                a[p++]=b;
                s=sub(s,b);
                continue;
            }
            if(len&1)
            {
                int l=len/2-1;
                int r=len/2+1;
                while(1)
                {
                    if(s[l]>s[r])
                        break;
                    l--;r++;
                    if(l<0)
                    break;
                }
                if(l!=-1)
                {
                    for(int i=0;i<l;i++)
                    {
                        b+=s[i];
                    }
                    for(int i=l;i<=r;i++)
                    {
                        b+=s[l]-1;
                    }
                    //if(l!=0)
                    //for(int i=l-1;i>=0;i--)
                    //b+=b[i];

                }
                else
                {
                    for(int i=0;i<=len/2;i++)
                    b+=s[i];
                    for(int i=len/2-1;i>=0;i--)
                    b+=s[i];

                }

            }
            else
            {
                int l=len/2-1;
                int r=len/2;
                while(1)
                {
                    if(s[l]>s[r])
                        break;
                    l--;r++;
                    if(l<0)
                    break;
                }
                if(l!=-1)
                {
                    for(int i=0;i<l;i++)
                    {
                        b+=s[i];
                    }
                    for(int i=l;i<=r;i++)
                    {
                        b+=s[l]-1;
                    }
                    if(l!=0)
                    for(int i=l-1;i>=0;i--)
                    b+=b[i];
                }
                else
                {
                    for(int i=0;i<len/2;i++)
                    b+=s[i];
                    for(int i=b.length()-1;i>=0;i--)
                    b+=b[i];
                }

            }

            //cout << s << " " << b << endl;
            a[p++]=b;
            s=sub(s,b);
        }
        if(s!="0")
        a[p++]=s;
        cout << p <<endl;
        for(int i=0;i<p;i++)
        cout << a[i] << endl;
    }
}
