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
int N,Q,C;
pair<int,int> ques[500005];//<r,l>


int sum[500005];
int lowbit(int x){return x&(-x);}
void add(int pos,int val){
	while(pos<=N){
		sum[pos]+=val;
		pos+=lowbit(pos);
	}
}
int query(int pos){
	int re=0;
	while(pos>0){
		re+=sum[pos];
		pos-=lowbit(pos);
	}
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>Q;
	for(int i=1;i<=N;i++) cin>>C[i]
;	for(int i=1;i<=Q;i++){
		cin>>ques[i].second>>ques[i].first;
	}
	sort(ques+1,ques+1+Q);

	return 0;
}



