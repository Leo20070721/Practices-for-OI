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
int N,M,ans;
vector<int> amap[200005];
stack<int> fin;

int root[200005];
int findRoot(int q){
	if(root[q]==q) return q;
	return root[q]=findRoot(root[q]);
}
void merge(int a,int b){
	a=findRoot(a),b=findRoot(b);
	root[b]=a;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	for(int i=N;i>=1;i--){
		fin.push(ans);
		bool confidental=true;
		for(int son:amap[i]){
			if(son<i) continue;
			if(confidental){
				confidental=false;
				root[i]=root[son];
			}else{
				if(findRoot(i)==findRoot(son)) continue;
				merge(i,son);
				ans--;
			}
		}				
		if(confidental){
			root[i]=i;
			ans++;
		}
	}
	
	while(!fin.empty()){
		cout<<fin.top()<<"\n";
		fin.pop();
	}

	return 0;
}



