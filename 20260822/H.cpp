#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
inline void _QuickStream(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

const bool _QuickStreamOpen=false;
const int _TEST=0;
//-------------------------------------
lli N,S,T,nowS,nowT,could[32],A[100005],ans=1;
const lli MOD=1e9+7;

lli inv[100005];
void invInit(){
    inv[1]=1;
    for(lli i=2;i<=100000;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
}


lli Cnt(lli n,lli m){
    lli re=1;
    for(lli i=n-m+1;i<=n;i++){
        re*=i;
        re%=MOD;
    }
    for(lli i=1;i<=m;i++){
        re*=inv[i];
        re%=MOD;
    }
    return re;
}
lli add(lli q,bool jo,bool must){
    lli re=0,i=1;
    if(jo==false) i=2;
    for(;i<=q;i+=2){
        re+=Cnt(q,i);
        re%=MOD;
    }
    if(jo==false && must==false) re++;
    re%=MOD;
    //cout<<re<<" ?\n";
    return re;
}

signed main(){
    if(_QuickStreamOpen)_QuickStream();
    invInit();

    cin>>N>>S>>T;

    for(int i=1;i<=N;i++){
        cin>>A[i];
        nowS|=A[i];
        nowT^=A[i];
        for(int j=0;j<=30;j++){
            if(!(A[i]&1)) could[j]++;
            A[i]>>=1;
        }
    }

    for(int i=0;i<=30;i++){
        if(((S>>i)&1)==0 && ( ((T>>i)&1)==1||((nowS>>i)&1)==1 )){
        	cout<<"0\n";
        	return 0;
		}
		if(!((S>>i)&1)) continue;
        if(((T>>i)&1) == ((nowT>>i)&1))
            ans*=add(could[i],false,!((nowS>>i)&1));
        else
            ans*=add(could[i],true ,!((nowS>>i)&1));
        ans%=MOD;
    }

    cout<<ans<<"\n";

    return 0;
}
