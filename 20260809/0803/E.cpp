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
int n[255],num,ans[255],len,K;

void read(){
	char cget;cget=getchar();
	while(cget<'0' || '9'<cget) cget=getchar();
	while('0'<=cget && cget<='9'){
		n[++num]=cget-'0';
		cget=getchar();
	}
	while(cget<'0' || '9'<cget) cget=getchar();
	while('0'<=cget && cget<='9'){
		K=K*10+cget-'0';
		cget=getchar();
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	read();
	//for(int i=1;i<=num;i++){cout<<n[i];}cout<<"\n";
	
	for(int i=1;i<=num;i++){
		if(num-i<K) break;
		int minn=10,pos;
		for(int j=i;j<=i+K;j++){
			if(n[j]<minn){
				minn=n[j];
				pos=j;
			}
		}
		ans[++len]=n[pos];
		K-=pos-i;
		i=pos;
		//cout<<"num:"<<n[pos]<<" K="<<K<<" i="<<i<<"\n";
	}
	
	bool flag=false;
	for(int i=1;i<=len;i++){
		if(ans[i]){flag=true;}
		if(flag) cout<<ans[i];
	}
	if(flag) cout<<"\n";
	else cout<<"0\n";
	
	

	return 0;
}



