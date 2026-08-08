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
set<char> yuan,hs;
void init(){
	yuan.insert('a');
	yuan.insert('e');
	yuan.insert('i');
	yuan.insert('o');
	yuan.insert('u');
	
	hs.insert('s');
	hs.insert('c');
	hs.insert('z');
}
void work(string w){
	if(w.size()==1){
		cout<<w<<w<<" ";
		return ;
	}
	else if(w.size()==2){
		cout<<w<<" ";
		return ;
	}
	
	int bgn=1;
	if(hs.find(w[0])!=hs.end() && w[1]=='h'){
		if(_TEST>=20) cout<<"Find sh/ch/zh start!\n";
		if(w[0]=='s') cout<<"u"; //sh->u
		else if(w[0]=='c') cout<<"i"; //ch->i
		else cout<<"v"; //zh->v
		bgn++;
	}else{
		cout<<w[0]; 
	}	
	if(yuan.find(w[0])!=yuan.end()){
		if(_TEST>=20) cout<<"Find yuan start!\n";
		bgn--;
	}
	
	if(w.size()-bgn==1){cout<<w[bgn]<<" ";return;}
	if(_TEST>=20)cout<<"Chk bgn:"<<w[bgn]<<"\n";
	switch(w[bgn]){	
		case 'i':{			
			switch(w[bgn+1]){
				case 'u':{cout<<"q ";break;}//iu->q
				case 'e':{cout<<"p ";break;}//ie->p
				case 'o':{cout<<"s ";break;}//iong->s
				case 'n':{
					if(w.size()-bgn==2) cout<<"b ";//in->b
					else cout<<"k ";//ing->k
					break;
				}
				case 'a':{
					if(w.size()-bgn==2) cout<<"x ";//ia->x
					else if(w[bgn+2]=='o') cout<<"n ";//iao->n
					else{
						if(w.size()-bgn==3) cout<<"m ";//ian->m
						else cout<<"l ";//iang->l
					}
					break;
				} 
			}
			break;
		}
		case 'e':{
			switch(w[bgn+1]){
				case 'i':{cout<<"w ";break;}//ei->w
				case 'n':{
					if(w.size()-bgn==2) cout<<"f ";//en->f
					else cout<<"g ";//eng->g
					break;
				}
			}
			break;
		}
		case 'u':{
			switch(w[bgn+1]){
				case 'a':{
					if(w.size()-bgn==2) cout<<"x ";//ua->x
					else if(w[bgn+2]=='i') cout<<"k ";//uai->k
					else{
						if(w.size()-bgn==3) cout<<"r ";//uan->r
						else cout<<"l ";//uang->l
					}
					break;
				} 
				case 'e':{cout<<"t ";break;}//ue->t
				case 'n':{
					if(w.size()-bgn==2) cout<<"y ";//un->y
					else cout<<"g ";//ung->g
					break;
				}
				case 'o':{cout<<"o ";break;}//uo->o
				case 'i':{cout<<"v ";break;}//ui->v
			}
			break;			
		}
		case 'o':{
			switch(w[bgn+1]){
				case 'n':{cout<<"s ";break;}//ong->s
				case 'u':{cout<<"z ";break;}//ou->z
			}
			break;
		}
		case 'a':{
			switch(w[bgn+1]){
				case 'i':{cout<<"d ";break;}//ai->d
				case 'n':{
					if(w.size()-bgn==2) cout<<"j ";//an->j
					else cout<<"h ";//ang->h
					break;
				}
				case 'o':{cout<<"c ";break;}//ao->c
			}			
			break;
		}
	}
	return;
}

void split(string s){
	if(_TEST>=20) cout<<"Spilt:"<<s<<"\n";
	string word="";
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]!=' ' && s[i]!='\n' && s[i]!='\0'){
			word=word+s[i];
		}else{
			work(word);
			word="";
		}
	}
	work(word);
	cout<<"\n";
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	init();

	string lget;
	getline(cin,lget);
	while(lget.size()>0){		
		split(lget);		
		getline(cin,lget);
	}

	return 0;
}



