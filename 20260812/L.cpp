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
const int MAXN=2e5+12;
int N,M;
int num[MAXN],C[MAXN];
int dep[MAXN],dfnIn[MAXN],dfnOut[MAXN],T;
vector<int> amap[MAXN];

void DFS(int now,int dad){
	dfnIn[now]=++T;
	dep[now]=dep[dad]+1;
	for(int nxt:amap[now])
		if(nxt!=dad) DFS(nxt,now);
	dfnOut[now]=T;	
}
int lowbit(int x){return x&(-x);}
void add(int pos,int val){
	while(pos<=N){
		C[pos]+=val;
		pos+=lowbit(pos);
	}
}
int query(int pos){
	int re=0;
	while(pos>0){
		re+=C[pos];
		pos-=lowbit(pos);
	}
	return re;
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>num[i];
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	DFS(1,0);
	
	while(M--){
		int op,x;cin>>op>>x;
		int l=dfnIn[x],r=dfnOut[x]+1;
		int pn=(dep[x]%2?1:-1);
		if(op==1){
			int v;cin>>v;			 
			add(l,v*pn);add(r,-v*pn);
		}else{
			cout<<num[x]+pn*query(l)<<"\n";
		}
	}

	return 0;
}



