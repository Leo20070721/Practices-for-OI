#include<bits/stdc++.h>
using namespace std;
#define lli long long int

#define MaxN 1000005
#define MaxM 200005
//------------------------------
int N,M;
int ST[MaxN][21];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int ST_find(int l,int r)
{
	int k=log2(r-l+1);
	return max(ST[l][k],ST[r-(1<<k)+1][k]);	
 } 
//------------------------------
int ai;
int main(){
	N=read();M=read();
	for(register int I=1;I<=N;I++) cin>>ST[I][0];
	
	for(register int j=1;j<=21;j++)
	for(register int i=1;i+(1<<j)-1<=N;i++)
		{ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);}

	int l,r;
	for(register int I=1;I<=M;I++)
	{
		l=read();r=read();
		printf("%d\n",ST_find(l,r));
	}
	
	return 0;
}
