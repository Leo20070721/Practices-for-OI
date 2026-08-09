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
const int MAXS=1e8+12;
vector<lli> prime;
bool not_prime[MAXS];
lli MAXN;
int T;
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

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>MAXN>>T;
	init();
	while(T--){
		int Q;cin>>Q;
		cout<<prime[Q-1]<<"\n";
	}

	return 0;
}



