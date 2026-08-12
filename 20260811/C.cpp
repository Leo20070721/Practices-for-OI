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
struct Edge{
	int a;int b;int v;
	bool operator< (const Edge& a)const{return v<a.v;}
}edge[200005];

int fa[5005];
int findFa(int x){return fa[x]==x?x:fa[x]=findFa(fa[x]);}
void merge(int x,int y){
	x=findFa(x),y=findFa(y);
	fa[x]=y;
}

int N,M;
int ans,cnt,sum;

void init(){for(int i=1;i<=N;i++) fa[i]=i;}

void Kruskal(){
	if(N==1){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=M;i++){		
		int afa=findFa(edge[i].a),bfa=findFa(edge[i].b);
		if(afa==bfa) continue;
		merge(afa,bfa);
		cnt++;
		ans+=edge[i].v;
		if(cnt==N-1) return;
	}
	return;
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}	
	
	cin>>N>>M;
	init();
	for(int i=1;i<=M;i++){
		cin>>edge[i].a>>edge[i].b>>edge[i].v;
		sum+=edge[i].v;
	}
	sort(edge+1,edge+1+M);
	Kruskal();
	
	cout<<sum-ans<<"\n";

	return 0;
}



