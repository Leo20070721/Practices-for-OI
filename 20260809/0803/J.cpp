#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define ull unsigned long long
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
ull hashMOD1=1e9+7,hashBase1=114;
ull hash1(string s){
	ull re;
	for(unsigned int i=0;i<s.size();i++) re=(re*hashBase1+(ull)s[i])%hashMOD1;
	return re;
}
ull hashMOD2=212370440130137957,hashBase2=514;
ull hash2(string s){
	ull re;
	for(unsigned int i=0;i<s.size();i++) re=(re*hashBase2+(ull)s[i])%hashMOD2;
	return re;
}
//-------------------------------------------
int N;
set < pair<ull,ull> > dict;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	while(N--){
		string sget;cin>>sget;
		dict.insert(make_pair(hash1(sget),hash2(sget)));
	}
	
	cout<<dict.size()<<"\n";

	return 0;
}



