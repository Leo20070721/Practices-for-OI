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
int N,K;
int xs[25];
int ans=0;

bool isPrime(int a){
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}

void dfs(int dep,int pos,int sum){
	if(dep==K+1){
		if(isPrime(sum)){
			//cout<<sum<<"\n";
			ans++;			
		}
		return;
	}
	
	if(N-pos+1<K-dep+1) return;
	
	for(int i=pos;i<=N-K+dep;i++){
		dfs(dep+1,i+1,sum+xs[i]);
	}
	return;	
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>K;
	for(int i=1;i<=N;i++)
		cin>>xs[i];
	
	dfs(1,1,0);
	cout<<ans<<"\n";

	return 0;
}



