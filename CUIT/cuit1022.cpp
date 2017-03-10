#include<bits/stdc++.h>

using namespace std;



int a[4];

int main()
{
    while(cin >> a[0] >>a[1]>>a[2]>>a[3])
    {
         int k=0;
        int sum;          
        int i,j,x,z,y;
        int op=0;
        for(x=0; x<4; x++)
        {
            for(y=0; y<4; y++)
            {
                for(z=0; z<4; z++)
                {
                    if(x!=y&&x!=z&&y!=z)
                    {
                        for(i=0; i<4; i++)
                        {
                            for(j=0; j<4; j++)
                            {
                                sum=0;
                                op=0;
                                switch(i)
                                {
                                case 0:
                                    sum+=a[x]+a[y];
                                    op++;

                                    break;
                                case 1:
                                    if(a[x]>a[y])
                                    {
                                        sum+=a[x]-a[y];
                                        op++;
                                    }
                                    break;
                                case 2:
                                    sum+=a[x]*a[y];
                                    op++;
                                    break;
                                case 3:
                                {
                                    if(a[x]%a[y]==0)
                                    {
                                        sum+=a[x]/a[y];
                                        op++;
                                    }
                                    break;
                                }
                                }
                                switch(j)
                                {
                                    case 0:
                                        sum+=a[z];
                                        op++;
                                        break;
                                    case 1:
                                        if(sum>a[z])
                                        {
                                            sum-=a[z];
                                            op++;
                                        }
                                        break;
                                    case 2:
                                        sum*=a[z];
                                        op++;
                                        break;
                                    case 3:
                                {
                                    if(sum%a[z]==0)
                                    {
                                        op++;
                                        sum/=a[z];
                                    }

                                    break;
                                }
                                }
                                if(sum==24&&op==2)
                                {
                                    k=1;
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }
        if(!k)
            cout << "No" <<endl;
        else
            cout << "Yes" << endl;
    }
}
