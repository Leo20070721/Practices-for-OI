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
int N,M;
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

	cin>>N>>M;
	for(int i=1;i<=M;i++) cin>>X[i].l>>X[i].r;
	sort(X+1,X+1+M,cmp);
	
	int end=X[1].r,ans=0;
	for(int i=2;i<=M;i++){
		if(X[i].l<end) end=min(X[i].r,end);
		else{
			ans++;
			end=X[i].r;
		}
	}
	if(end!=0) ans++;
	
	cout<<ans<<"\n";

	return 0;
}



