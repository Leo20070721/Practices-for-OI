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
int N;
struct Stu{
	int uid;
	bool sex;
	int school;
	int score;
	
	Stu(){
		uid=school=score=0;
		sex=false;
	}
	
	Stu(int i,int s,int sc,int sco){
		uid=i;sex=(s==1?true:false);school=sc;score=sco;
	}
}stu[105];

bool cmp(Stu a,Stu b){
	return a.score>b.score;
}
bool chg(Stu a,Stu b){
	return a.uid<b.uid;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int n=1;n<=N;n++){
		int _S,_SC,_SCO;cin>>_S>>_SC>>_SCO;
		stu[n]=Stu(n,_S,_SC,_SCO);
		if(n<=4){for(int i=1;i<=n;i++) {cout<<i<<" ";}cout<<"\n";continue;}
	
		vector<Stu> sorted;
		for(int i=1;i<=n;i++) sorted.push_back(stu[i]);
		sort(sorted.begin(),sorted.end(),cmp);
		
		vector<Stu> A,B;
		bitset<105> vis;
		int buck[105];memset(buck,0,sizeof(buck));
		
		int sexflag=-1;
		for(int i=0;i<4;i++){
			A.push_back(sorted[i]);
			vis[i]=true;
			buck[sorted[i].school]++;
			if(sexflag==-1) sexflag=sorted[i].sex;
			if(sexflag<2 && sexflag!=sorted[i].sex) sexflag=2;
		} 
		if(sexflag==2){
			A.push_back(sorted[4]);
			vis[4]=true;
			buck[sorted[4].school]++;
		}
		else{
			for(unsigned int i=4;i<sorted.size();i++){
				if(sorted[i].sex!=sorted[3].sex){
					A.push_back(sorted[i]);
					vis[i]=true;
					buck[sorted[i].school]++;
					break;
				}
			}
		}
		
		for(unsigned int i=0;i<sorted.size();i++){
			if(B.size()==12)break;
			if(vis[i]) continue;
			if(buck[sorted[i].school] >= 5 )continue;
			B.push_back(sorted[i]);
			buck[sorted[i].school]++;
		}
		
		sort(A.begin(),A.end(),chg);
		sort(B.begin(),B.end(),chg);
		for(unsigned int i=0;i<A.size();i++) cout<<A[i].uid<<" ";
		for(unsigned int i=0;i<B.size();i++) cout<<B[i].uid<<" ";
		cout<<"\n";
	}

	return 0;
}



