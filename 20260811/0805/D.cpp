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
	int nxt[MAXN][2],cnt;
	
	public:		
		void insert(lli i){
			int pos=0;
			stack<bool> Q;
			for(int k=0;k<32;k++){
				bool c=i&1;
				Q.push(c);
				i>>=1;
			}
			for(int k=0;k<32;k++){
				int c=Q.top();Q.pop();
				if(!nxt[pos][c]) nxt[pos][c]=++cnt;
				pos=nxt[pos][c];
			}
		}
		
		lli query(lli i){
			int pos=0;lli re=0;
			stack<bool> Q;
			for(int k=0;k<32;k++){
				bool c=i&1;
				Q.push(c);
				i>>=1;
			}
			for(int k=0;k<32;k++){
				int c=!Q.top();
				if(nxt[pos][c]){
					pos=nxt[pos][c];
					re=(re<<1)+1;
				}else{
					pos=nxt[pos][Q.top()];
					re<<=1;
				}				
				Q.pop();
			}
			return re;
		}
}; 

int N;lli A[100005],ans;
Trie trie;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		trie.insert(A[i]);
	}
	for(int i=1;i<=N;i++){
		ans=max(ans,trie.query(A[i]));
	}
	cout<<ans<<"\n";

	return 0;
}



