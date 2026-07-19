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
class Queue{
	int cache[10005];
	int begin,end;
	
	public:
		Queue(){
			this->begin=this->end=0;
		}
		
		void push(int x) {this->cache[end++]=x;}
		void pop(){
			if(begin<end) begin++;
			else cout<<"ERR_CANNOT_POP\n"; 
		}
		int query(){
			if(begin<end){
				cout<<cache[begin]<<"\n";
				return cache[begin];
			}else{
				cout<<"ERR_CANNOT_QUERY\n";
				return 0;
			}
		}
		int size(){
			cout<<end-begin<<"\n";
			return end-begin;
		}
		
		void DEBUG(){
			cout<<"Queue: begin="<<begin<<"  end="<<end<<"\n";
			for(int i=begin;i<end;i++){
				cout<<cache[i]<<" ";
			}cout<<"\n";
		}
};

int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	Queue Q;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		switch(sget[0]-'0'){
			case 1:{
				int num;cin>>num;
				Q.push(num);
				break;
			}
			case 2:{
				Q.pop();
				break;
			}
			case 3:{
				Q.query();
				break;
			}
			case 4:{
				Q.size();
				break;
			}
		}
		if(_TEST>=10){
			cout<<"case:"<<sget[0]-'0'<<"\n";
			for(unsigned int j=0;j<sget.size();j++){
				cout<<sget[j]<<" ";
			}cout<<"\n";	
		}		
		if(_TEST>=5) Q.DEBUG();
	}
	

	return 0;
}



