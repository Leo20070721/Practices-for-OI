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
vector<int> prefix(string s){
	vector<int> pi(s.size());
	for(unsigned int i=1;i<s.size();i++){
		int j=pi[i-1];
		while(j>0 && s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i]=j;
	}
	return pi;
}

vector<int> KMP(string ques,string sub){
	string Q=sub+"#"+ques;
	vector<int> ans=prefix(Q);
	
	int len1=sub.size();
	vector<int> re;
	for(unsigned int i=len1+1;i<ans.size();i++){
		if(ans[i]==len1) re.push_back(i-2*len1+1);
	}
	
	return re;
}

string s1,s2;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>s1>>s2;
	vector<int> ans1=KMP(s1,s2),ans2=prefix(s2);
	
	for(unsigned int i=0;i<ans1.size();i++) cout<<ans1[i]<<"\n";
	for(unsigned int i=0;i<ans2.size();i++) cout<<ans2[i]<<" ";
	cout<<"\n";

	return 0;
}



