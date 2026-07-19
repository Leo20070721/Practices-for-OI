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
lli A,B;
int lenOfA,lenOfB;
int ans[10];
vector <lli> fans;

int lengthOf(int a){
	int ans=0;
	while(a>0){
		a/=10;ans++;
	}
	return ans;
}

bool isPrime(lli a){
	for(lli i=2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}

lli addZero(lli basic,int num){
	lli re=basic;
	for(int i=1;i<=num;i++){
		re*=10;
	}
	return re;
}

void dfs(int dep,int goal,int nans[]){
	if(dep*2!=goal+2 && dep*2!=goal+3){
		if(dep==1){
			for(int i=1;i<=9;i++){
				nans[dep]=i;
				dfs(dep+1,goal,nans);
			}
		}else{
			for(int i=0;i<=9;i++){
				nans[dep]=i;
				dfs(dep+1,goal,nans);
			}
		}
		return;		
	}
	
	lli basic=0;
	for(int i=1;i<dep;i++)   basic=basic*10+nans[i];
	if (goal%2==1)           dep--;
	for(int i=dep-1;i>0;i--) basic=basic*10+nans[i];
	//cout<<goal<<":"<<basic<<"\n";
	if(A<=basic && basic<=B){
			
		if(isPrime(basic)) fans.push_back(basic);
	}
	
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>A>>B;
	lenOfA=lengthOf(A);lenOfB=lengthOf(B);
	
	for(int i=lenOfA;i<=lenOfB;i++){
		dfs(1,i,ans);
	}
	
	for(unsigned int i=0;i<fans.size();i++){
		cout<<fans[i]<<"\n";
	}	

	return 0;
}



