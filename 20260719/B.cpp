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

int Q;
list <int> cache[1000005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>Q;
	while(Q--){
		string sget;int a;cin>>sget>>a;
		int bgn,end;
		end=sget.size();
		if(end>4){
			for(bgn=0;sget[bgn]!='_';bgn++);
		}
		
		if(end==4){//size,back
			if(sget[0]=='s') cout<<cache[a].size()<<"\n";
			else {
				if(cache[a].size()==0) continue;
				cout<<cache[a].back()<<"\n";
			}
		}else if(end==5){//front
		if(cache[a].size()==0) continue;
			cout<<cache[a].front()<<"\n";
		}else if(bgn==3){//pop
			if(cache[a].size()==0) continue;
			if(end==8) cache[a].pop_back();
			else cache[a].pop_front();
		}else{//push
			int x;cin>>x;
			
			if(end==9) cache[a].push_back(x);
			else cache[a].push_front(x);			
		}
		
		if(_TEST>=5){
			for(int i=0;i<1000005;i++){
				if(cache[i].size()>0){
					cout<<i<<": "<<cache[i].front()<<"->"<<cache[i].back()<<"\n";
				}
			}
		}
	}


	return 0;
}



