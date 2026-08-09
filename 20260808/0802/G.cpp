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
const int MAXS=1e6+12,MAXN=65536;
vector<lli> prime;
bool not_prime[MAXS],vis[MAXS];
void init(){
	for(int i=2;i<=MAXN;i++){
		if(!not_prime[i]) prime.push_back(i);
		
		for(unsigned int j=0;j<prime.size();j++){
			if(i*prime[j]>MAXN) break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

lli L,R,ans;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	init();
	
	cin>>L>>R;
	if(L==1) L=2;
	for(unsigned int i=0;i<prime.size();i++){
		for(lli j=max(2ll,L/prime[i])*prime[i] ;j<=R;j+=prime[i]){
			if(j-L>=0){
				vis[j-L]=true;
				//cout<<j<<" not a prime.\n";
			}
		}
	}
	
	for(int i=0;i<=R-L;i++) if(!vis[i])ans++;

	cout<<ans<<"\n";

	return 0;
}



