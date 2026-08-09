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
string F,M,B;
struct Node{
	int l,r;
}tree[12];

void DFS(int ml,int mr,int bl,int br){
	cout<<B[br];//<<" DFS: "<<ml<<" "<<mr<<" | "<<bl<<" "<<br<<"\n";
	if(bl>=br) return;
	
	int i;
	for(i=ml;i<=mr;i++) if(M[i]==B[br]) break;
	
	if(i-ml>0) DFS(ml,i-1,bl,bl+(i-ml)-1);
	if(mr-i>0) DFS(i+1,mr,bl+(i-ml),br-1); 
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>M>>B;
	
	DFS(0,B.size()-1,0,B.size()-1);

	return 0;
}



