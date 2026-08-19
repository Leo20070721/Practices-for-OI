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
int N,K;
int A[10004];

void getInit(){
	int a1anda2,a1anda3,a2anda3;
	int a1ora2,a1ora3,a2ora3;
	int a1a2,a1a3,a2a3;
	
	cout<<"and 1 2"<<endl;
	cin>>a1anda2;
	cout<<"and 1 3"<<endl;
	cin>>a1anda3;
	cout<<"and 2 3"<<endl;
	cin>>a2anda3;
	cout<<"or 1 2"<<endl;
	cin>>a1ora2;
	cout<<"or 1 3"<<endl;
	cin>>a1ora3;
	cout<<"or 2 3"<<endl;
	cin>>a2ora3;
	
	a1a2=a1anda2+a1ora2;
	a1a3=a1anda3+a1ora3;
	a2a3=a2anda3+a2ora3;
	
	A[1]=(a1a2+a1a3-a2a3)/2;
	A[2]=a1a2-A[1];
	A[3]=a1a3-A[1];
	return;
}
void get(int q){
	int a1and,a1or;
	cout<<"and 1 "<<q<<endl;
	cin>>a1and;
	cout<<"or 1 "<<q<<endl;
	cin>>a1or;
	A[q]=a1and+a1or-A[1];
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K;
	getInit();
	for(int i=4;i<=N;i++) get(i);
	sort(A+1,A+1+N);
	cout<<"finish "<<A[K]<<endl;

	return 0;
}



