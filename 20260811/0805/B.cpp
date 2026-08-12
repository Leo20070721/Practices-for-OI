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
	int nxt[MAXN][27],cnt;
	bool is[MAXN],hav[MAXN];
	
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
		
		void find(string s){
			int pos=0;
			for(unsigned int i=0;i<s.size();i++){
				int c=s[i]-'a';
				if(!nxt[pos][c]){
					cout<<"WRONG\n";
					return;
				}
				pos=nxt[pos][c];
			}
			if(is[pos]){
				if(hav[pos]) cout<<"REPEAT\n";
				else{
					hav[pos]=true;
					cout<<"OK\n";
				}
			}else cout<<"WRONG\n";
		}
}; 

int N,M;
Trie trie;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		trie.insert(sget);
	}
	cin>>M;
	for(int i=1;i<=M;i++){
		string sget;cin>>sget;
		trie.find(sget);
	}


	return 0;
}



