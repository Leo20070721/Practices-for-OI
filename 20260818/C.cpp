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
const int MAXN=200005;

struct Node{int b;int pos;int ans;}B[MAXN];
bool cmpb(Node& x,Node& y){return x.b<y.b;}
bool cmpp(Node& x,Node& y){return x.pos<y.pos;}

int N,M;
int A[MAXN],now;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=M;i++){
		cin>>B[i].b;
		B[i].pos=i;
	}
	
	sort(A+1,A+1+N);
	sort(B+1,B+1+M,cmpb);
	
	for(int i=1;i<=M;i++){
		while(A[now+1]<=B[i].b && now<N) now++;
		B[i].ans=now;
	}
	sort(B+1,B+1+M,cmpp);
	
	for(int i=1;i<=M;i++)cout<<B[i].ans<<" "; cout<<"\n";
	
	return 0;
}



