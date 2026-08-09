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
map<string,int> num;
int pos=-1;
string ques; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>ques;
	for(unsigned int i=0;i<ques.size();i++)
		if(ques[i]>='A' && ques[i]<='Z') ques[i]=ques[i]-'A'+'a';
	num[ques]=0;
	string sget,word="";
	getline(cin,sget);getline(cin,sget);	
	//cout<<sget<<"\n";
	for(unsigned int i=0;i<sget.size();i++){
		if(sget[i]=='\0' || sget[i]=='\n' || sget[i]==' '){
			//cout<<"Word:"<<word<<"\n";
			if(word==ques){
				num[ques]++;
				if(pos==-1) pos=i-ques.size();
			}
			word="";
			continue;
		}
		if(sget[i]>='A' && sget[i]<='Z') sget[i]=sget[i]-'A'+'a';
		word=word+sget[i];
	}
	
	if(pos!=-1)cout<<num[ques]<<" "<<pos<<"\n";
	else cout<<"-1\n";

	return 0;
}



