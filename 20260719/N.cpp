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
stack< pair<int,int> > Q;
pair<int,bool> fin[105];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	string sget;cin>>sget;
	for(unsigned int i=0;i<sget.size();i++){
		if(sget[i]=='(') Q.push(make_pair(i,-1));
		else if(sget[i]=='[') Q.push(make_pair(i,-2));
		else if(sget[i]==')'){
			if(!Q.empty() && Q.top().second==-1){
				fin[i]=make_pair(1,true);
				fin[Q.top().first]=make_pair(-1,true);
				Q.pop();
			}else{
				fin[i]=make_pair(1,false);
			}
		}else if(sget[i]==']'){
			if(!Q.empty() && Q.top().second==-2){
				fin[i]=make_pair(2,true);
				fin[Q.top().first]=make_pair(-2,true);
				Q.pop();
			}else{
				fin[i]=make_pair(2,false);
			}
		}
	}
	
	while(!Q.empty()){
		fin[Q.top().first]=make_pair(Q.top().second,false);
		Q.pop();
	}
	
	for(unsigned int i=0;i<sget.size();i++){
		if(fin[i].second){
			switch(fin[i].first){
				case -2:{cout<<"[";break;}
				case -1:{cout<<"(";break;}
				case 1:{cout<<")";break;}
				case 2:{cout<<"]";break;}
			}
		}else{
			switch(abs(fin[i].first)){
				case 1:{cout<<"()";break;}
				case 2:{cout<<"[]";break;}
			}
		}
	}cout<<"\n";

	return 0;
}



