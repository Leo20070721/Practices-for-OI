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
const int MAXN=1000005;
int N,M;
int sorted[MAXN];

int BinarySearch(int q){
	int L=1,R=N;
	while(L<R){
		int mid=(L+R)>>1;
		if(sorted[mid]>=q) R=mid;
		else L=mid+1;
	}
	if(sorted[R]==q) return R;
	else return -1;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>sorted[i];
	for(int i=1;i<=M;i++){
		int q;cin>>q;
		cout<<BinarySearch(q)<<" ";
	}cout<<"\n";
	return 0;
}



