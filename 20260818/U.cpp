#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
int N,A[10000007],L[10000007],R[10000007],root;
stack<int> Right;

int lans,rans;
void DFS(int now){
	lans^=now*(L[now]+1);
	rans^=now*(R[now]+1);
	if(L[now]) DFS(L[now]);
	if(R[now]) DFS(R[now]);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	
	for(int i=1;i<=N;i++){
		int lst=0;
		while(!Right.empty() && A[Right.top()]>A[i]){
			lst=Right.top();
			Right.pop();
		} 
		if(Right.empty()) root=i;
		else R[Right.top()]=i;
		Right.push(i);
		
		if(lst) L[i]=lst;		
	}
//	cout<<"Root:"<<root<<"\n";
//	for(int i=1;i<=N;i++) cout<<L[i]<<" "; cout<<"\n";
//	for(int i=1;i<=N;i++) cout<<R[i]<<" "; cout<<"\n";
	
	DFS(root);
	cout<<lans<<" "<<rans<<"\n";

	return 0;
}



