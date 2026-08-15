#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=false;
const int _TEST=0;
//-----------------------------------------
const int MAXN=105;
int N,M;
int A[MAXN][MAXN],B[MAXN][MAXN],C[MAXN][MAXN];// (i,j)是谁 
int lineA[MAXN][MAXN],lineB[MAXN][MAXN];      // (i,j)属于谁 
bool colA[MAXN][MAXN],colB[MAXN][MAXN];       // i列的属于j行是否被占用  
signed main(){
	if(_QuickStream) _QuickStreamOpen();
	//读入------------------------ 
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>A[i][j];
	//预处理归属------------------------ 
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			lineA[i][j]=(A[i][j]-1)/M+1;
	//规划B------------------------ 
	for(int j=1;j<=M;j++){
		B[1][j]=j;
		colA[j][lineA[1][j]]=true; 
	}
		
	for(int i=2;i<=N;i++){
		queue< int > Q;
		for(int j=1;j<=M;j++) Q.push(j);
		
		while(!Q.empty()){
			int now=Q.front();Q.pop();
			bool flag=true;
			for(int k=1;k<=M;k++){
				if(B[i][k]) continue;
				if(colA[k][lineA[i][now]]) continue;
				
				flag=false;
				B[i][k]=now;
				colA[k][lineA[i][now]]=true;
				break;
			}
			
			if(flag){
				for(int k=1;k<=M;k++){
					if(colA[k][lineA[i][now]]) continue;
					Q.push(B[i][k]);
					colA[k][lineA[i][B[i][k]]]=false;
					
					B[i][k]=now;
					colA[k][lineA[i][now]]=true;
					break;
				}
			}
		}	
	}
	//为B赋值------------------------
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			lineB[i][j]=lineA[i][B[i][j]];
			B[i][j]=A[i][B[i][j]]; 
		}
	} 
	//输出B------------------------
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)cout<<B[i][j]<<" "; cout<<"\n";
	}
	//逐列按照行属重排 
	for(int j=1;j<=M;j++)
		for(int i=1;i<=N;i++)
			C[lineB[i][j]][j]=B[i][j];
	//输出C------------------------
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)cout<<C[i][j]<<" "; cout<<"\n";
	}
	return 0;
}

