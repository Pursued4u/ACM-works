#include<cstdio>
const int N = 100000 + 5;
bool prime[N];//prime[i]��ʾi�ǲ�������
int p[N], tot;//p[N]����������
void init(){
    for(int i = 2; i < N; i ++) prime[i] = true;//��ʼ��Ϊ����
    for(int i = 2; i < N; i++){
        if(prime[i]) p[tot ++] = i;//������������
        for(int j = 0; j < tot && i * p[j] < N; j++){
            prime[i * p[j]] = false;
            if(i % p[j] == 0) break;//��֤ÿ������������С��������ɸȥ
        }
    }
}
int main(){
    init();
}

/*
����Ԥ����ÿ��������������
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
����Ԥ����ÿ����������������
#include<cstdio>
#include<vector>
using namespace std;
const int N = 100000 + 5;
vector<int > prime_factor[N];
void init(){
    for(int i = 2; i < N; i ++){
        if(prime_factor[i].size() == 0){//���i������
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
