#include <bits/stdc++.h>
#include <ctime>
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
const int MAXN=4;
int ques[MAXN+2]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	mt19937 myrand(time(nullptr));

	cout<<"1\n";
	cout<<MAXN<<"\n";
	for(int i=1;i<=MAXN;i++) ques[i]=i;
	const int rint=myrand()%20000007;
	for(int i=1;i<=rint;i++) next_permutation(ques+1, ques+1+MAXN);
	for(int i=1;i<=MAXN;i++)  cout<<ques[i]<<" "; cout<<"\n";

	return 0;
}



