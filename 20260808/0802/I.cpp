#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
inline void _OpenFiles(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
lli exgcd(lli a,lli b,lli &x,lli &y){
	if(b==0){
		x=1,y=0;return a;
	}
	lli re=exgcd(b,a%b,x,y);
	tie(x,y)=make_tuple(y,x-(a/b)*y);
	return re;
} 

void put128(__int128 a){
	if(a<0){putchar('-');a=-a;}
	if(a>0){
		if(a>10)put128(a/10);
		putchar('0'+a%10);		
	} 
}

lli N,A[12],B[12];
__int128 mult=1,ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>B[i]>>A[i];
		mult*=B[i];
	}
	
	for(int i=1;i<=N;i++){
		lli x,y;
		exgcd(mult/B[i],B[i],x,y);
		x=(x%B[i]+B[i])%B[i];
		ans+=(A[i]*(mult/B[i])%mult)*x;
		ans%=mult;
	}
	
	put128(ans);

	return 0;
}



