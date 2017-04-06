#include<bits/stdc++.h>
using namespace std;
#define db double
#define eps 1e-7
#define ll long long
int sgn(db x){
    if(x<-eps||x>eps) return 1;
    else return 0;
}
int main(){
    ll a,c,d,k,p;
    scanf("%I64d%I64d%I64d%I64d%I64d",&a,&c,&d,&k,&p);
    ll ans1=0;
    ll ans2=0;

    for(int i=1;i<=k;i++){
        ans1+=c+d*i;
        ans2+=(c+d*i)*(100+p);
    }
    ans1+=a;
    db ansr1 = db(ans1)/1.0;
    db ansr2 = db(ans2)/100.0;
    if(!sgn(ansr1-ansr2))
    {
         cout << "Insurance" <<endl;
        cout << "0.00" << endl;
    }
    else if(ansr2>ansr1)
    {
        cout << "Cash" << endl;
        printf("%.8f\n",ansr2-ansr1);
    }
    else
    {
        cout << "Insurance" <<endl;
        printf("%.8f\n",ansr1-ansr2);

    }

}