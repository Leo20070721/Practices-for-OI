#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStream(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

const bool _QuickStreamOpen=true;
const int _TEST=0;
//-------------------------------------
int a,b;
signed main(){
    if(_QuickStreamOpen)_QuickStream();
    cin>>a>>b;
    if(a%2==0) swap(a,b);

    if(a>b) cout<<"1\n";
    else cout<<"2\n";
    return 0;
}

