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
int T;

string work(string s1,string s2){
	string re;
	for(unsigned int i=0;i<s1.size();i++){
		re=re+s2[i];
		re=re+s1[i];
	}
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	for(int t=1;t<=T;t++){
		bool flag=false;lli cnt=0;
		lli N;cin>>N;
		string C1,C2,fin,temp;
		set<string> cache;
		cin>>C1>>C2>>fin;

		do{
			if(cnt>0) cache.insert(temp);
			temp=work(C1,C2);
			cnt++;
			C1=C2="";
			for(unsigned int i=0;i*2<temp.size();i++){C1=C1+temp[i];}
			for(unsigned int i=temp.size()/2;i<temp.size();i++){C2=C2+temp[i];}

			if(temp == fin){
				flag=true;
				break;
			}
			if(_TEST>=10) cout<<"temp "<<cnt<<":"<<temp<<"\n";
		}while(cache.find(temp)==cache.end());

		cout<<t<<" ";
		if(flag) cout<<cnt<<"\n";
		else cout<<"-1\n";
	}
	

	return 0;
}



