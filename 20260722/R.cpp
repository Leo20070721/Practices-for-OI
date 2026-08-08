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
struct Drink{
	int pos;int time;
}a[200005];
bool cmp(Drink a,Drink b){
	return a.time<b.time;
}
int N,M,D;
int ans[200005],lst,day;
deque<int> Q;
stack<int> Front;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M>>D;
	lst=N;
	for(int i=1;i<=N;i++){
		int iget;cin>>iget;
		a[i].pos=1;a[i].time=iget;
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=N;i++) Q.push_back(i);
	
	while(!Q.empty() || !Front.empty()){
		int now=-1e9-24;		
		day++;
		cout<<"Now is day "<<day<<"\n";
		while(!Front.empty()){
			Q.push_front(Front.top());
			Front.pop();
		}
		
		while(!Q.empty() && now<=M){
			int pos=Q.front();Q.pop_front();		
			if(now+D>a[pos].time){Front.push(pos);continue;}
			
			now=a[pos].time;
			ans[pos]=day;	
		}				
	}
	
	cout<<day<<"\n";
	for(int i=1;i<=N;i++) cout<<ans[a[i].pos]<<" ";
	cout<<"\n";

	return 0;
}



