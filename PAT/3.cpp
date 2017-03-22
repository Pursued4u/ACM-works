#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
map<string,int>mp;
map<string,int>vis;
map<string,int>cnt;
int main(){
    int n;
    cin >> n;
    getchar();

    while(n--){
        char s[maxn];
        gets(s);
        string a = "";
        int flag = 0;
        for(int i=0;i<strlen(s);i++){
        if(s[i]=='#'){
            for(int j=1;i+j<strlen(s);j++){
                
                if(s[j+i]=='#'){

                    if(!vis[a])
                    cnt[a]++;
                    mp[a]++;
                    vis[a]=1;
                   a="";
                    i = j+i+1;
                   break;
                   }
                if(tolower(s[i+j])>='a'&&tolower(s[i+j]<='z'))
                {if(a=="")
                a+=toupper(s[i+j]);
                else
                a+=tolower(s[i+j]);
            }
            if(j>40)break;
        }
        }
        vis.clear();
    }
    map<string,int>::iterator it;
        int maxx = 0;
        string ans;
        for(it = mp.begin();it!=mp.end();it++){
            maxx = max(it->second,maxx);
            ans = it->first;
        }
        vector<string>ve;
        for(it = mp.begin(); it!=mp.end();it++){
            if(it->second==maxx){
                ve.push_back(it->first);
            }
        }
        sort(ve.begin(),ve.end());
        for(int i=0;i<ve.size();i++){
            if(i!=ve.size()-1){
                cout << ve[i] << " ";
            }
            else
                cout << ve[i] <<endl;
        }
        cout << cnt[ans] << endl;
        cout << "And " << mp.size()-ve.size() <<" more ..." << endl;
}
