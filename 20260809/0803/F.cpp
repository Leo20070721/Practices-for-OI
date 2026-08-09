#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define ull unsigned long long
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
ull hashMOD1=1e9+7,hashBase1=114;
ull hash1(string s){
	ull re=0;
	for(unsigned int i=0;i<s.size();i++) re=(re*hashBase1+(ull)s[i])%hashMOD1;
	return re;
}
ull revhash1(string s){
	ull re1=0,re2=0;
	for(unsigned int i=0;i<s.size();i++) re1=(re1*hashBase1+(ull)s[i])%hashMOD1;
	for(int i=s.size()-1;i>=0;i--) re2=(re2*hashBase1+(ull)s[i])%hashMOD1;
	return (re1+re2)%hashMOD1;
}
ull hashMOD2=212370440130137957,hashBase2=514;
ull hash2(string s){
	ull re=0;
	for(unsigned int i=0;i<s.size();i++) re=(re*hashBase2+(ull)s[i])%hashMOD2;
	return re;
}
ull revhash2(string s){
	ull re1=0,re2=0;
	for(unsigned int i=0;i<s.size();i++) re1=(re1*hashBase2+(ull)s[i])%hashMOD2;
	for(int i=s.size()-1;i>=0;i--) re2=(re2*hashBase2+(ull)s[i])%hashMOD2;
	return (re1+re2)%hashMOD2;
}
pair<ull,ull> Hash(string s){
	return make_pair(hash1(s),hash2(s));
} 
pair<ull,ull> revHash(string s){
	return make_pair(revhash1(s),revhash2(s));
} 
//-------------------------------------------
bool check(string s){
	int mid=(s.size()-1)>>1;
	int mov=(s.size()%2?0:1);
	for(int i=0;i<=mid;i++){
		if(s[mid-i]!=s[mid+i+mov]) return false;
	}
	return true;
}

struct Node{
	pair<ull,ull> shash1, shash2;
	int num1,num2;
	string s1,s2;
	bool self;
	
	Node(){
		num1=num2=0;
		self=false;
		shash1=shash2=make_pair(0,0);
	}
	
	Node(string s){
		num1=num2=0;
		self=check(s);
		s1=s;
		shash1=Hash(s1);
		reverse(s.begin(), s.end());
		s2=s;
		shash2=Hash(s2);
	}
	
	void add(string s){
		pair<ull,ull> shash=Hash(s);
		if(shash==shash1) num1++;
		else num2++;
	}
};
map < pair<ull,ull> , Node> dict;
int N,M;
string ansfb,ansm;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		pair<ull,ull> revhash=revHash(sget);
		
		
		if(dict.find(revhash)==dict.end()){
			dict[revhash]=Node(sget);
		} 
		dict[revhash].add(sget);
	}
	
	for(auto x : dict){
		Node Nget=x.second;
		if(Nget.self){
			for(int i=1;2*i<=Nget.num1;i++){
				ansfb=ansfb+Nget.s1;
			}
		}else{
			for(int i=1;i<=min(Nget.num1,Nget.num2);i++){
				ansfb=ansfb+Nget.s1;
			}
		}
		
		if(Nget.self && Nget.num1%2){ansm=Nget.s1;}
	}
	
	cout<<2*ansfb.size()+ansm.size()<<"\n";
	cout<<ansfb<<ansm;
	reverse(ansfb.begin(), ansfb.end());
	cout<<ansfb<<"\n";
 
	return 0;
}



