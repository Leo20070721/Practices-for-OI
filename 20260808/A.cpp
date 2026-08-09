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
struct Node{
	Node* Left;
	Node* Right;
	
	Node(){
		Left=Right=nullptr;
	}
	Node(Node* L,Node* R){
		Left=L;
		Right=R;
	}
}; 
Node bintree[1000005];
int N,ans;

void DFS(Node* now,int dep){
	if(now->Left==nullptr && now->Right==nullptr){
		ans=max(ans,dep);
		return;
	}
	if(now->Left!=nullptr) DFS(now->Left,dep+1);
	if(now->Right!=nullptr) DFS(now->Right,dep+1);
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		int l,r;cin>>l>>r;
		if(l!=0) bintree[i].Left=&bintree[l];
		if(r!=0) bintree[i].Right=&bintree[r];
	}
	
	DFS(&bintree[1],1);
	cout<<ans<<"\n";

	return 0;
}



