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
int N;
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

	cin>>N;
	for(int i=1;i<=N;i++) cin>>X[i].l>>X[i].r;
	sort(X+1,X+1+N,cmp);
	
	int end1=-1,end2=-1;
	bool flag=true;
	for(int i=1;i<=N;i++){
		if(X[i].l>end1){
			end1=X[i].r;
		}else if(X[i].l>end2){
			end2=X[i].r;
		}else{
			flag=false;
			break;
		}
	}
	
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}



