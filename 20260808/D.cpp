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
	freopen("P2052_15.in","r",stdin);
	//freopen(".out","w",stdout);
}
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
const int MAXS=1e6+12;
int N;

struct Node{
	bool vis;
	vector<int> son;
	vector<lli> val;
	lli sum;
}tree[MAXS];

lli init(int now){		
	if(tree[now].vis) return 0;
	tree[now].vis=true;
	
	lli re=1;
	for(unsigned int i=0;i<tree[now].son.size();i++){
		re+=init(tree[now].son[i]);
	}
	tree[now].sum=re;
	
	tree[now].vis=false;
	return re;
}

lli sum;
void DFS(int now){	
	tree[now].vis=true;
	
	for(unsigned int i=0;i<tree[now].son.size();i++){
		int nxt=tree[now].son[i];
		if(tree[nxt].vis) continue;
//		cout<<"Road "<<now<<"->"<<nxt<<":"<<tree[now].val[i]*fabs(tree[now].sum+1+fanum-2*tree[now].num[i])<<"\n";
		sum+=tree[now].val[i]*abs(tree[1].sum-2ll*tree[tree[now].son[i]].sum);
		
		DFS(nxt);
	}
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N;
	for(int i=1;i<N;i++){
		int f,t;lli v;cin>>f>>t>>v;
		tree[f].son.push_back(t);tree[f].val.push_back(v);
		tree[t].son.push_back(f);tree[t].val.push_back(v);
	}
	init(1);
//	for(int i=1;i<=N;i++){
//		cout<<"tree["<<i<<"].sum="<<tree[i].sum<<"\n";
//		for(unsigned int j=0;j<tree[i].num.size();j++)
//			cout<<"tree["<<i<<"].num["<<j<<"]="<<tree[i].num[j]<<"\n";
//	}
	DFS(1);
	cout<<sum<<"\n";	

	return 0;
}



