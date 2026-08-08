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
vector<int> amap[100005];
int in[100005],out[100005],len[100005],N,M,ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int x,y;cin>>x>>y;
		amap[x].push_back(y);
		out[x]++;in[y]++;
	}
	
	queue<int> Q;
	for(int i=1;i<=N;i++){
		if(in[i]==0){
			len[i]=1;
			Q.push(i);
		}
	}
	
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		ans=max(ans,len[now]);
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i];
			len[nxt]=max(len[nxt],len[now]+1);
			in[nxt]--;
			if(in[nxt]==0) Q.push(nxt);
		}
	}
 	
 	cout<<ans-1<<"\n";

	return 0;
}



