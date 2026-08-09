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
lli N,P;

lli inv[3000005]; 
void init(int n,int p){
	inv[1]=1;
	for(int i=2;i<=N;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
	}
	return ;
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>P;
	init(N,P);
	for(int i=1;i<=N;i++) cout<<inv[i]<<"\n";

	return 0;
}



