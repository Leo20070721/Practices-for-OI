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
int N,D;
struct line{
	int l,r;
}X[1000005];
bool cmp(line a,line b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>D;
	for(int i=1;i<=N;i++) cin>>X[i].l>>X[i].r;
	sort(X+1,X+1+N,cmp);
	
	int end=-1e9-5,ans=0;
	for(int i=1;i<=N;i++){
		if(X[i].l>end+D-1){			
			end=X[i].r;
			ans++;
		}else if(X[i].r<end){
			end=X[i].r;
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}



