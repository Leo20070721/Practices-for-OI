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
int N;
lli K;
lli buck[1000005],maxn;
void Manacher(string &s){
	int n=s.size();
	vector<lli> D(n);
	for(lli i=0,l=0,r=-1;i<n;i++){
		lli k= (i>r)? 1:min(D[l+r-i],r-i+1);
		while(0<=i-k && i+k<n && s[i-k]==s[i+k]) k++;
		D[i]=k--;
		if(i+k>r) l=i-k,r=i+k;
		if(!(D[i]%2)){
			buck[D[i]-1]++;
			maxn=max(maxn,D[i]-1);
		}
	}
//	for(int i=0;i<n;i++) cout<<D[i]<<" "; cout<<"\n";
//	for(int i=1;i<=maxn;i++) 
//		if(buck[i])cout<<i<<":"<<buck[i]<<" "; cout<<"\n";
}

const lli MOD=19930726;
lli quick_pow(lli a,lli x){
	lli re=1,t=a;
	while(x>0){
		if(x&1) re*=t;
		t*=t;
		re%=MOD;t%=MOD;
		x>>=1;
	}
	return re;
}

string sget,ques;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>K;
	cin>>sget;
	for(unsigned int i=0;i<sget.size();i++){
		ques+="#";
		ques+=sget[i];
	}ques=ques+"#";
	Manacher(ques);
	
	lli sum=0,ans=1;
	while(K>0){
		sum+=buck[maxn];
		//cout<<K<<" "<<maxn<<"="<<sum<<":"<<ans<<"\n";
		if(sum<K){
			if(maxn==1){
				cout<<"-1\n";
				return 0;
			}
			K-=sum;
			ans*=quick_pow(maxn,sum);ans%=MOD;
		}else{
			ans*=quick_pow(maxn,K);ans%=MOD;
			break;
		}
		maxn-=2;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}



