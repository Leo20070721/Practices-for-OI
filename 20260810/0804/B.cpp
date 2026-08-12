#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
const int MAXS=4e7+24;
lli z[MAXS];
int ans1,ans2;
string a,b;
void Zfunction(string& s){
	int n=s.size();
	memset(z,0,sizeof(z));
	z[0]=n;ans1=n+1;
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r && z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			z[i]=max(0ll,r-i+1);
			while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
		}
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
		ans1^=(i+1)*(z[i]+1);
	}
	return ;
} 

void exKMP(string& ques,string& sub){
	string Q=sub+"#"+ques;
	Zfunction(Q);
	for(unsigned int i=1;i<=a.size();i++){
		ans2^=i*(z[i+b.size()]+1);
	}
	return;
} 


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>a>>b;
	Zfunction(b); cout<<ans1<<"\n";
	exKMP(a,b); cout<<ans2<<"\n";
	return 0;
}



