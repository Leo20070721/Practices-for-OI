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
Ld X[4],Y[4];

Ld length(int a,int b){
	return sqrt((X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b])); 
}
Ld Xmult(int a,int b,int c){
	return (X[b]-X[a])*(Y[c]-Y[b])-(Y[b]-Y[a])*(X[c]-X[b]);
}
int sgn(Ld q){
	if(q>0) return 1;
	else if(q<0) return -1;
	else return 0;
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	for(int i=0;i<4;i++){
		int x,y;	
		scanf(" (%d,%d)",&x,&y);
		X[i]=x;Y[i]=y;
	}
	
	for(int i=0;i<3;i++){
		if(X[i]==X[3] && Y[i]==Y[3]){
			cout<<"4\n";
			return 0;
		}
	}
	for(int i=0;i<3;i++){
		if(length(i,3)+length((i+1)%3,3)==length(i,(i+1)%3)){
			cout<<"3\n";
			return 0;
		}
	}
	for(int i=0;i<3;i++){
		if(sgn(Xmult(i,(i+1)%3,(i+2)%3))
		!= sgn(Xmult(i,3,(i+2)%3))){
			cout<<"2\n";
			return 0;
		}
	}
	cout<<"1\n";

	return 0;
}



