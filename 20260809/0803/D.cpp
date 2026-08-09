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
int num;string sget;
stack<char> ques; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>sget;
	for(int i=0;i<sget.size();i++){
		if(!ques.empty() && sget[i]==ques.top()){
			num++;
			ques.pop();
		}else{
			ques.push(sget[i]);
		}
	}
	
	//cout<<num<<"\n";
	cout<<(num%2?"Yes":"No")<<"\n";

	return 0;
}



