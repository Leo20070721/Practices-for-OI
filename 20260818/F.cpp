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
int N,A[200005];
lli ans,L,R;
bool used[24];

void del(int q){
	for(int i=1;q>0;i++){
		if(q&1) used[i]=false;
		q>>=1;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	
	for(L=1,R=1;R<=N;R++){
		int temp=A[R];
		
		for(int i=1;temp>0;i++){
			if(!(temp&1)){
				temp>>=1;
				continue;
			}
			while(used[i]){
				del(A[L]);L++;
			}
			used[i]=true;
			temp>>=1;
		}
		ans+=R-L+1;
	}
	cout<<ans<<"\n";

	return 0;
}



