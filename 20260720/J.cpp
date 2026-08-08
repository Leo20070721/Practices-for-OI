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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
#define lowbit(x) ((x)&(-x))
int N,ans;
lli stop[24];

void DFS(int deep,lli vis,lli l,lli r){
	if(deep==N+1){
		ans++;
		return;
	}
	lli maxl=((1<<N)-1);
	lli cant=(vis|l|r|stop[deep])&maxl;
	lli pos=cant^maxl;
	while(pos>0){
		lli push=lowbit(pos);
		DFS(deep+1,vis|push,(l|push)<<1,(r|push)>>1);
		pos-=push;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		lli temp=0;
		for(int j=1;j<=N;j++){
			char cget;cin>>cget;
			temp=(temp<<1)+(cget=='.'?1:0);
		}
		stop[i]=temp;		
	}
	
	DFS(1,0,0,0);
	
	cout<<ans<<"\n";

	return 0;
}



