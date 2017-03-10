#include<cstdio>
const int N = 100000 + 5;
bool prime[N];//prime[i]表示i是不是质数
int p[N], tot;//p[N]用来存质数
void init(){
    for(int i = 2; i < N; i ++) prime[i] = true;//初始化为质数
    for(int i = 2; i < N; i++){
        if(prime[i]) p[tot ++] = i;//把质数存起来
        for(int j = 0; j < tot && i * p[j] < N; j++){
            prime[i * p[j]] = false;
            if(i % p[j] == 0) break;//保证每个合数被它最小的质因数筛去
        }
    }
}
int main(){
    init();
}

/*
比如预处理每个数的所有因数
#include<cstdio>
#include<vector>
using namespace std;
const int N = 100000 + 5;
vector<int > factor[N];
void init(){
    for(int i = 2; i < N; i ++){
        for(int j = i; j < N; j += i){
            factor[j].push_back(i);
        }
    }
}
int main(){
    init();
}*/
/*
比如预处理每个数的所有质因数
#include<cstdio>
#include<vector>
using namespace std;
const int N = 100000 + 5;
vector<int > prime_factor[N];
void init(){
    for(int i = 2; i < N; i ++){
        if(prime_factor[i].size() == 0){//如果i是质数
            for(int j = i; j < N; j += i){
                prime_factor[j].push_back(i);
            }
        }
    }
}
int main(){
    init();
}
*/
