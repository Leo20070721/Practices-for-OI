#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStream(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

const bool _QuickStreamOpen=true;
const int _TEST=0;
//-------------------------------------
const lli MOD=998244353;
lli N,K,A[12];
bool op[12];

lli quick_pow(lli a,lli n){
    lli re=1,temp=a;
    while(n>0){
        if(n&1){
            re*=temp;
            re%=MOD;
        }
        temp*=temp;
        temp%=MOD;
        n>>=1;
    }
    return re;
}

lli DFS(int now){
    if(now==K){
        if(op[now]){
            lli re=0;
            for(int i=1;i<=N;i++){
                re+=A[i];
                re%=MOD;
            }
            return re;
        }else{
            lli re=1;
            for(int i=1;i<=N;i++){
                re*=A[i];
                re%=MOD;
            }
            return re;
        }
    }

    if(op[now]){
        lli re=DFS(now+1);
        re*=N;
        re%=MOD;
        return re;
    }else{
        lli re=DFS(now+1);
        re=quick_pow(re,N);
        return re;
    }

}

signed main(){
    if(_QuickStreamOpen)_QuickStream();
    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>A[i];
    string sget;cin>>sget;
    for(int i=1;i<=K;i++){
        op[i]=(sget[i-1]=='s'?true:false);//T:sum F:product
    }

    cout<<DFS(1)<<"\n";

    return 0;
}
