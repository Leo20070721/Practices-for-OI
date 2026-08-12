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
vector<int> amap[105];
int in[105];
queue<int> Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		int iget;cin>>iget;
		while(iget){
			amap[i].push_back(iget);
			in[iget]++;
			cin>>iget;
		}
	}
	
	for(int i=1;i<=N;i++)
		if(!in[i]) Q.push(i);
		
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		cout<<now<<" ";
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i];
			in[nxt]--;
			if(!in[nxt]) Q.push(nxt);
		}
	}cout<<"\n";

	return 0;
}



