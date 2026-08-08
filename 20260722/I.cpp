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
struct node{
	int x,y;
	bool flag;
	
	node(){
		x=y=0;flag=false;
	}
	node(int a,int b,bool c){
		x=a;y=b;flag=c;
	}
};
int DP[3005][3005];
node mem[3005][3005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	string a,b;cin>>a>>b;
	for(unsigned int i=1;i<=a.length();i++){
		for(unsigned int j=1;j<=b.length();j++){						
			if(DP[i-1][j]>=DP[i][j-1]){
				DP[i][j]=DP[i-1][j];
				mem[i][j]=node(i-1,j,false);
			}
			else{
				DP[i][j]=DP[i][j-1];
				mem[i][j]=node(i,j-1,false);
			}
			
			if(a[i-1]==b[j-1]){
				if(DP[i-1][j-1]+1>DP[i][j]){
					DP[i][j]=DP[i-1][j-1]+1;
					mem[i][j]=node(i-1,j-1,true);
				}					
			} 
		}
	}
	
//	for(unsigned int i=0;i<=a.length();i++){
//		for(unsigned int j=0;j<=b.length();j++){
//			cout<<DP[i][j]<<" ";
//		}cout<<"\n";
//	}cout<<"\n";
//	for(unsigned int i=0;i<=a.length();i++){
//		for(unsigned int j=0;j<=b.length();j++){
//			cout<<"("<<mem[i][j].first<<","<<mem[i][j].second<<") ";
//		}cout<<"\n";
//	}cout<<"\n";
	
	stack<char> ans;
	int posa=a.length(),posb=b.length();
	while(posa!=0 && posb!=0){
		if(mem[posa][posb].flag) ans.push(a[posa-1]);
		node nxt=mem[posa][posb];
		posa=nxt.x;posb=nxt.y;
	}
	
	while(!ans.empty()){
		cout<<ans.top();ans.pop();
	}cout<<"\n";

	return 0;
}



