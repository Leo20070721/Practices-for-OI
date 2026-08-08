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
int buck[26],sum;
vector<string> ans;

void DFS(int deep,string s){
	if(deep==sum+1){
		ans.push_back(s);
		return;
	}
	for(int i=0;i<26;i++){
		if(buck[i]){
			buck[i]--;
			DFS(deep+1,s+char('a'+i));
			buck[i]++;
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	string sget;cin>>sget;
	sum=sget.size();
	for(unsigned int i=0;i<sget.size();i++){
		buck[sget[i]-'a']++;
	}
	
	DFS(1,"");
	
	cout<<ans.size()<<"\n";
	for(unsigned int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
	
	return 0;
}



