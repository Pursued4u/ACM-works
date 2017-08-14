#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define ll double
int m,n,i;
char s[125][6];
char temp[6];
char a[105][6];
map<char,int>mp;
string ans;

int dist(string b)
{
    int dis=0;
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(mp[b[i]]>mp[b[j]])
                dis++;
        }
    }
    return dis;
}
int main()
{

    int minn;
    int k=1;
    char temp[6]= "ABCDE";
    strcpy(s[0],temp);
    while(next_permutation(temp,temp+5))
    {
        strcpy(s[k++],temp);
    }
    while(cin >> m&&m!=0)
    {
        getchar();
        for(i=0; i<m; i++)
        {
            cin >> a[i];
        }
        minn=1000000;
        int j;
        int sum;
        for(int i=0; i<120; i++)
        {
            sum=0;
            for(j=0; j<5; j++)
            {
                mp[s[i][j]]=j+1;
            }
            for(j=0; j<m; j++)
            {
                sum+=dist(a[j]);
            }
           // printf("%s",s[i]);
            //cout <<i<<" "<<sum <<endl;
            if(sum<minn)
            {
                minn=sum;
                ans=s[i];
            }
        }
        cout << ans;
        printf(" is the median ranking with value %d.\n",minn);
    }


}
