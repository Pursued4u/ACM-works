#include<ext/pb_ds/assoc_container.hpp>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <cstddef>
#include<cmath>
#include<ext/pb_ds/tree_policy.hpp>
#include<map>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef long long LL;

__gnu_pbds::tree<LL,null_type,less<LL>,rb_tree_tag,tree_order_statistics_node_update>T;

map<int,int>MP;

int Q,opt;

LL x;

int main()
{
    scanf("%d",&Q);
    while (Q--)
    {
        scanf("%d%lld",&opt,&x);
        if (opt==1)
            T.insert((x<<20)+(MP[x]++));
        else if (opt==2)
        {
            T.erase(T.find((x<<20)+(--MP[x])));
            if (!MP[x])
                MP.erase(MP.find(x));
        }
        else if (opt==3)
            printf("%d\n",T.order_of_key(x<<20)+1);
        else if (opt==4)
            printf("%lld\n",*T.find_by_order(x-1)>>20);
        else if (opt==5)
        {
            map<int,int>::iterator key=MP.lower_bound(x);
            key--;
            printf("%d\n",key->first);
        }
        else
        {
            map<int,int>::iterator key=MP.upper_bound(x);
            printf("%d\n",key->first);
        }
    }
    return 0;
}
