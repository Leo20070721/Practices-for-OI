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
pair<int,int> Q[200005];
int N,now;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>Q[i].second>>Q[i].first;
	
	sort(Q+1,Q+1+N);
	
	for(int i=1;i<=N;i++){
		now+=Q[i].second;
		if(now<=Q[i].first) continue;
		cout<<"No\n";
		//cout<<"i="<<i<<":now="<<now<<" need="<<Q[i].first<<"\n";
		return 0;
	}
	cout<<"Yes\n";

	return 0;
}



