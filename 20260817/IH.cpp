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
struct Node{
	lli X;lli Y;
}node[400005];

bool cmpX(const Node& a,const Node& b){return a.X<b.X;}
bool cmpY(const int a,const int b){return node[a].Y<node[b].Y;}

inline lli sqrlen(int a,int b){
	return (node[a].X-node[b].X)*(node[a].X-node[b].X)+(node[a].Y-node[b].Y)*(node[a].Y-node[b].Y);
}

int temp[400005],lst;
lli ans=1e16;
void solve(int L,int R){
	if(R<=L) return ;
	if(R==L+1){
		ans=min(ans,sqrlen(L,R));
		return ;
	}
	vector<int> Q;
	int MID=(L+R)>>1;
	int m=node[MID].X;
	solve(L,MID);solve(MID+1,R);
	lst=0;
	for(int i=L;i<=R;i++)
		if((node[i].X-m)*(node[i].X-m) <= ans)
			temp[++lst]=i;
	sort(temp+1,temp+1+lst,cmpY);
	int pos=1; 
	for(int i=1;i<=lst;i++){
		while(pos<=lst && (node[temp[pos]].Y-node[temp[i]].Y)*(node[temp[pos]].Y-node[temp[i]].Y)<=ans)pos++;
		for(int j=i+1;j<pos;j++){	
//			cout<<"i="<<Q[i]<<" j="<<Q[j]<<" :"<<sqrlen(Q[i],Q[j])<<"\n";	
			ans=min(ans,sqrlen(temp[i],temp[j]));
		}
			
	}
//	cout<<L<<"->"<<R<<":"<<ans<<"\n";
}

int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

//	cin>>N;
//	for(int i=1;i<=N;i++) cin>>node[i].X>>node[i].Y;
    scanf("%d ",&N);
	for(int i=1;i<=N;i++) scanf(" %lld %lld",&node[i].X,&node[i].Y);
	sort(node+1,node+1+N,cmpX);
	solve(1,N);
//	cout<<ans<<"\n";//I
	printf("%lld\n",ans);
//	Ld fin=sqrt(ans);printf("%.4Lf\n",fin);//H 

	return 0;
}



