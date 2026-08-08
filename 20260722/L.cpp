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
int N,T;
struct node{
	int m;int v;
	double per;
	node(){
		m=v=per=0.0;
	}
	node(int a,int b) {
		m=a;v=b;per=double(v)/double(m);
	}
}gold[105];
bool cmp(node a,node b){
	return a.per>b.per;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>T;
	for(int i=1;i<=N;i++){
		int m,v;cin>>m>>v;
		gold[i]=node(m,v);
	}
	sort(gold+1,gold+1+N,cmp);
	
	double have=0,ans=0;
	for(int i=1;i<=N;i++){
		if(have+gold[i].m<=T){
			ans+=gold[i].v;
			have+=gold[i].m;
		}
		else{
			ans+=(double(T)-have)*gold[i].per;
			break;
		}
	}
	printf("%.2lf\n",ans);

	return 0;
}



