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
const int MAXS=300012;
int N,M,DP[MAXS][26],word[MAXS],in[MAXS],ans;
vector<int> amap[MAXS];
queue<int> Q;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	string sget;cin>>sget;
	for(int i=1;i<=N;i++){
		word[i]=sget[i-1]-'a';
		DP[i][word[i]]++;
	}
	for(int i=1;i<=M;i++){
		int f,t;cin>>f>>t;
		amap[f].push_back(t);
		in[t]++;		
	}
	
	for(int i=1;i<=N;i++){
		if(in[i]==0){
			Q.push(i);
		}
	}
	
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i];
			for(int j=0;j<26;j++){
				if(j==word[nxt]){
					DP[nxt][j]=max(DP[nxt][j],DP[now][j]+1);
				}else{
					DP[nxt][j]=max(DP[nxt][j],DP[now][j]);
				}
				ans=max(ans,DP[nxt][j]);
			}			
			in[nxt]--;
			if(in[nxt]==0) Q.push(nxt);
		}
	}
	
	for(int i=1;i<=N;i++){
		if(in[i]>0){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<"\n";

	return 0;
}



