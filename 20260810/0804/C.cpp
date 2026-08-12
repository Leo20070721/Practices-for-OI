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

int Manacher(string &s){
	int n=s.size(),ans=0;
	vector<int> D(n);
	for(int i=0,l=0,r=-1;i<n;i++){
		int k= (i>r)? 1:min(D[l+r-i],r-i+1);
		while(0<=i-k && i+k<n && s[i-k]==s[i+k]) k++;
		D[i]=k--;
		if(i+k>r) l=i-k,r=i+k;
		ans=max(ans,D[i]-1);
	}
	//for(int i=0;i<n;i++) cout<<D[i]<<" "; cout<<"\n";
	return ans;
}

string sget,ques;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>sget;
	for(unsigned int i=0;i<sget.size();i++){
		ques+="#";
		ques+=sget[i];
	}ques=ques+"#";
	
	cout<<Manacher(ques)<<"\n";
	return 0;
}



