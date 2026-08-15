#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=true;
const int _TEST=0;
//-----------------------------------------
const int MAXN=5e5+24;
int N,Q,fa[MAXN];
lli V[MAXN],sum[MAXN],all[MAXN],dep[MAXN];
vector<int> amap[MAXN];
int dfnIn[MAXN],dfnOut[MAXN],T; 

pair<lli,lli> DFS(int now){
	dfnIn[now]=++T;
	dep[now]=dep[fa[now]]+1;
	lli resum=0,reall=0;
	for(int nxt:amap[now]){
		pair<lli,lli> pget=DFS(nxt);
		resum+=pget.first;reall+=pget.second;
	}
	sum[now]=resum;all[now]=reall;
	dfnOut[now]=T; 
	return make_pair(resum+V[now],reall+dep[now]*V[now]);
}

signed main(){
	if(_QuickStream) _QuickStreamOpen();

	cin>>N>>Q;
	for(int i=1;i<=N;i++) cin>>V[i];
	for(int i=2;i<=N;i++){
		cin>>fa[i];amap[fa[i]].push_back(i);
	}
	
	dep[0]=-1;
	pair<lli,lli> pget=DFS(1);
	sum[0]+=pget.first;all[0]+=pget.second;
	while(Q--){
		int x,y,z;cin>>x>>y;
//		for(int son:amap[y]){
//			if(dfnIn[son]<=dfnIn[x] && dfnOut[x]<=dfnOut[son]){
//				z=son;break;
//			}
//		}		
		int L=0,R=amap[y].size()-1;
		while(L<R){
			int MID=(L+R)>>1;
			int nowson=amap[y][MID];
			if(dfnOut[nowson]>=dfnOut[x]) R=MID;
			else L=MID+1;
		}
		z=amap[y][R];
		if(_TEST>=10){
			cout<<dfnOut[x]<<":";
			for(int nowson:amap[y]) cout<<dfnOut[nowson]<<" "; cout<<"\n";
		}	
		if(_TEST>=5) cout<<"z="<<z<<"\n";
		
		if(_TEST>=5) cout<<"Debug:"<<all[y]<<" "<<dep[y]<<" "<<sum[y]<<" "<<sum[x]<<" "
		<<(dep[x]-dep[y])<<" "<<V[x]<<" "<<z<<" "<<sum[z]<<" "<<V[z]<<"\n";
		
		cout<<(all[y]-dep[y]*sum[y])
			+(-sum[x])
			+(-(dep[x]-dep[y])*V[x])
			+sum[z]+V[z]
			<<"\n";
	}

	return 0;
}

