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
lli A,B,MOD=19260817,ans;

lli exgcd(int a,int b,int &x,int &y){
	if(b==0){x=1;y=0;return a;}
	lli re=exgcd(b,a%b,x,y);
	tie(x,y)=make_tuple(y,x-a/b*y);
	return re;
}

lli inverse(int a,int m){
	int x,y;
	exgcd(B,MOD,x,y);
	x=(x%MOD+MOD)%MOD;
	return x;
}

lli get_int(){
	lli re=0;char cget=getchar();
	while(cget<'0' || cget>'9') cget=getchar();
	while(cget>='0' && cget<='9'){
		re=re*10+cget-'0';
		re%=MOD;
		cget=getchar();
	}
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	A=get_int();B=get_int();
	if(B==0) cout<<"Angry!\n";
	else{		
		ans=A*inverse(B,MOD)%MOD;
		cout<<ans<<"\n";
	}


	return 0;
}



