#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=true;
//-----------------------------------------
const int MAXN=5e5+24;
int N,M,base[MAXN];
vector<int> amap[MAXN];int fa[MAXN];

int dfnIn[MAXN],dfnOut[MAXN],T;
void DFS(int now){
	dfnIn[now]=++T;
	for(int nxt:amap[now])
		DFS(nxt);
	dfnOut[now]=T;
}

int C[MAXN];
int lowbit(int x){return (x&(-x));}
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
	if(_QuickStream) _QuickStreamOpen();

	cin>>N>>M>>base[1];
	for(int i=2;i<=N;i++){
		cin>>base[i]>>fa[i];
		amap[fa[i]].push_back(i);
	}
	
	DFS(1);
	
	for(int i=1;i<=M;i++){
		char op;int a;cin>>op>>a;
		int l=dfnIn[a],r=dfnOut[a]+1;
		if(op=='p'){
			int x;cin>>x;
			add(l+1,x);add(r,-x);
		}else{
			cout<<base[a]+query(l)<<"\n";
		}
	}
	
	return 0;
}

