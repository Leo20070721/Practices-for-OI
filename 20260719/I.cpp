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
int M,N;
int A[200005],U[200005];
priority_queue<int> front;
priority_queue<int, vector<int>, greater<int> > back;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>M>>N;
	for(int i=1;i<=M;i++) cin>>A[i];
	for(int i=1;i<=N;i++) cin>>U[i];
	
	int pos=1;
	for(int i=1;i<=M;i++){
		if(front.size()>0 && front.top()>A[i]){
			front.push(A[i]);
			back.push(front.top());
			front.pop();
		}else{
			back.push(A[i]);
		}
		
		
		
		while(U[pos]==i){
			cout<<back.top()<<"\n";
			front.push(back.top());
			back.pop();
			pos++;
		}
		if(pos>N) break;
	}
	return 0;
}



