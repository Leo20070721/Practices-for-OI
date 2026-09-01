#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
//-----------------------------------------
void _QuickStream(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
//------------------------------------------
int N;

set<int> Nums;map<int,int> dict;
struct Kards{
	int A;int B;bool used;
}kards[20];
vector<int> Aards[40],Bards[40];
int Alst[40],Blst[40];

bool DFS(bool nowWho,int dep){
//	cout<<dep<<":"<<nowWho<<"\n";
//	for(unsigned int i=1;i<=Nums.size();i++) cout<<Alst[i]<<" "; cout<<"\n";
//	for(unsigned int i=1;i<=Nums.size();i++) cout<<Blst[i]<<" "; cout<<"\n";
	
	bool flag=!nowWho,could=false;
	
	for(unsigned int i=1;i<=Nums.size();i++){
		if(Alst[i]>1){
			could=true;
			
			int k1=0,k2=0;
			for(int k:Aards[i]){
				if(kards[k].used==false){
					if(k1) k2=k;
					else k1=k;
				}
				if(k2) break;
			}		
			
			if(k1&&k2){
				kards[k1].used=true;kards[k2].used=true;
				Alst[i]-=2;	
				bool bget=DFS(!nowWho,dep+1);
				Alst[i]+=2;	
				kards[k1].used=false;kards[k2].used=false;		
				
				if(bget==nowWho) {flag=nowWho;break;}
			}
			
		}
		if(Blst[i]>1){
			int k1=0,k2=0;
			for(int k:Bards[i]){
				if(kards[k].used==false){
					if(k1) k2=k;
					else k1=k;
				}
				if(k2) break;
			}
			
			if(k1&&k2){
				could=true;
				kards[k1].used=true;kards[k2].used=true;
				Blst[i]-=2;		
				bool bget=DFS(!nowWho,dep+1);
				Blst[i]+=2;	
				kards[k1].used=false;kards[k2].used=false;
				
				if(bget==nowWho) {flag=nowWho;break;}
			}			
		}
	}
	
	if(could==false) return !nowWho;
	else return flag;
}

signed main(){
//	_QuickStream();

	cin>>N;
	for(int i=1;i<=N;i++){
		int a,b;cin>>a>>b;
		if(Nums.find(a)==Nums.end()){Nums.insert(a);dict[a]=Nums.size();}
		if(Nums.find(b)==Nums.end()){Nums.insert(b);dict[b]=Nums.size();}
		kards[i].A=dict[a];kards[i].B=dict[b];kards[i].used=false;
		Aards[dict[a]].push_back(i);Alst[dict[a]]++;
		Bards[dict[b]].push_back(i);Blst[dict[b]]++;
	}
	
	if(DFS(true,1)) cout<<"Takahashi\n";
	else cout<<"Aoki\n";

	return 0;
}

