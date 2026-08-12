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
	int nxt[MAXN][64],num[MAXN],cnt;
	
	public:
		Trie(){}
		
		void init(){
			memset(nxt,0,sizeof(nxt));
			memset(num,0,sizeof(num));
			cnt=0;
		}
		void clear(){
			for(int i=0;i<=cnt;i++){
				num[i]=0;
				for(int j=0;j<64;j++) nxt[i][j]=0;
			}
			cnt=0;
		}
		
		int getnum(char c){
			if('0'<=c && c<='9') return c-'0';
			if('a'<=c && c<='z') return c-'a'+10;
			if('A'<=c && c<='Z') return c-'A'+36;
			return -1;
		}
		
		void insert(string& s){
			int pos=0;
			for(unsigned int i=0;i<s.size();i++){
				int c=getnum(s[i]);
				if(!nxt[pos][c]) nxt[pos][c]=++cnt;
				pos=nxt[pos][c];
				num[pos]++;
			}
		}
		
		int csfind(string s){
			int pos=0;
			for(unsigned int i=0;i<s.size();i++){
				int c=getnum(s[i]);
				if(!nxt[pos][c]) return 0;
				pos=nxt[pos][c];
			}
			return num[pos];
		}
}; 

int T;
Trie trie;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>T;
	while(T--){
		int N,Q;cin>>N>>Q;
		for(int i=1;i<=N;i++){
			string sget;cin>>sget;
			trie.insert(sget);
		}
		for(int i=1;i<=Q;i++){
			string sget;cin>>sget;
			cout<<trie.csfind(sget)<<"\n";
		}
		trie.clear();
	}

	return 0;
}



