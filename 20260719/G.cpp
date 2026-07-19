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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,K,ans;
pair<int,int> root[50005];

pair<int,int> findRoot(int x){
	if(root[x].first==x) return make_pair(x,0);
	pair<int,int> newRoot = findRoot(root[x].first);
	newRoot.second=(newRoot.second+root[x].second)%3;
	if(_TEST>=10)cout<<"uprt["<<x<<"]: fa="<<newRoot.first<<"  faop="<<newRoot.second<<"\n";
	root[x]=newRoot;
	return newRoot;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++){
		root[i]=make_pair(i,0);
	}
	
	while(K--){
		int op,x,y;cin>>op>>x>>y;
		if(x>N || y>N){
			if(_TEST>=10)cout<<"Loser!\n\n";
			ans++;continue;
		}
		
		pair<int,int> rootX,rootY;
		rootX=findRoot(x);rootY=findRoot(y);
		int fax,faopx,fay,faopy;
		fax=rootX.first;faopx=rootX.second;
		fay=rootY.first;faopy=rootY.second;
		
		if(op==1){
			if(fax==fay){
				if(faopx!=faopy) {
					ans++;
					if(_TEST>=5)cout<<"Liar!\n";
				}
			}else{
				root[fax]=make_pair(fay,(faopy-faopx+3)%3);
				if(_TEST>=10)cout<<"root["<<x<<"]: fa="<<fay<<"  faop="<<(faopy-faopx+3)%3<<"\n";
			}
		}else{//op==2
			if(x==y){
					ans++;					
					if(_TEST>=5)cout<<"Loser!\n\n";
					continue;
				}
			if(fax==fay){
				if((faopy-faopx+3)%3 != 1) {
					ans++;
					if(_TEST>=5)cout<<"Liar!\n";
					if(_TEST>=10)cout<<"Reason: faopx="<<faopx<<" faopy="<<faopy<<"\n";
				}
			}else{
				root[fax]=make_pair(fay,(faopy-faopx+2+3)%3);
				if(_TEST>=10)cout<<"root["<<x<<"]: fa="<<fay<<"  faop="<<(faopy-faopx+2+3)%3<<"\n";
			}
		}
		if(_TEST>=5)cout<<"\n";
	}
	
	cout<<ans<<"\n";

	return 0;
}



