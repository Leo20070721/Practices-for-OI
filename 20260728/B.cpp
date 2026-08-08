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
int N,H[200005],ans[200005];
stack<int> Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>H[i];
	
	for(int i=N;i>=1;i--){
		ans[i]=Q.size();
		while(!Q.empty()){
			if(Q.top()<H[i]) Q.pop();
			else break;
		}
		Q.push(H[i]);
	}
	
	for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
	cout<<"\n";

	return 0;
}



