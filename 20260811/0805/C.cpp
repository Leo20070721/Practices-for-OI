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
const int MAXN=3e6+24;
class Trie{	
	int nxt[MAXN][64],cnt;
	bool is[MAXN];
	
	public:		
		void insert(string& s){
			int pos=0;
			for(unsigned int i=0;i<s.size();i++){
				int c=s[i]-'a';
				if(!nxt[pos][c]) nxt[pos][c]=++cnt;
				pos=nxt[pos][c];
			}
			is[pos]=true;
		}
		
		int DFS(int now){
			int re=0;
			for(int i=0;i<26;i++)
				if(nxt[now][i]) 
					re=max(re,DFS(nxt[now][i])); 
			return re+is[now];
		}
		
		int getans(){
			return DFS(0);
		}
}; 

int T;
Trie trie;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	int N;cin>>N;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		trie.insert(sget);
	}

	cout<<trie.getans()<<"\n";
	

	return 0;
}



