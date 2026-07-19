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
int root[200005];

int findRoot(int x){
	if(root[x]==x) return x;
	//root[x]=findRoot(root[x]);
	return root[x]=findRoot(root[x]);//
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) root[i]=i;
	while(M--){
		int z,x,y;cin>>z>>x>>y;
		int fax,fay;
		fax=findRoot(x);fay=findRoot(y);
		
		if(z==1){
			if(fax!=fay){
				root[fax]=fay;
			}
		}else{
			
			if(fax==fay) cout<<"Y\n";
			else cout<<"N\n";
		}
	}

	return 0;
}



