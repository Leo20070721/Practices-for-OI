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
const int MAXS=1e6+12;
int N,Q,D[MAXS],K,DP[MAXS];
struct Node{
	int pos;
	int H;
	int damn;
	
	Node(){pos=H=damn=0;}
	Node(int p,int h,int d){
		pos=p;H=h;damn=d;
	}
}DQ[MAXS];int l,r; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>D[i];
	cin>>Q;
	while(Q--){
		l=r=0;cin>>K;
		DQ[0]=Node(1,D[1],0);r++;
		for(int i=2;i<=N;i++){
			while(l<r && DQ[l].pos+K < i) l++;
			
			DP[i]=DQ[l].damn+(DQ[l].H<=D[i]?1:0); 
			
			while(l<r && DQ[r-1].damn > DP[i]) r--;
			while(l<r && DQ[r-1].damn == DP[i] && DQ[r-1].H <= D[i]) r--;
			DQ[r]=Node(i,D[i],DP[i]);r++;
		}
		cout<<DP[N]<<"\n";
	}

	return 0;
}



