#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
char control1(ll i){
    if((i+1) % 2==0) return 'N';
    else return 'C';
}
char control2(ll i){
    if((i+1) % 2==0) return 'C';
    else return 'N';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin>> t;
    while(t--)
    {
        ll n; cin >> n;
        ll c1=0, c2=0;
        string v1,v2; cin >> v1 >> v2 ;
        ll f1=1 , f2=1; // if this is 1 then we can move ahead
        ll fg=1;
        for(ll i=0;i<n;i++){
            if(f1==1){
                c1=i;
                if(v1[i]=='<' && control1(i)=='N') f1=-1;
            }
            if(f2==1){
                c2=i;
                if(v2[i]=='<' && control2(i)=='N') f2=-1;
            }

            if(control2(i)=='C' && v1[i]=='>' && f2==1) {f1=1;c1=i;}
            if(control1(i)=='C' && v2[i]=='>' && f1==1) {f2=1;c2=i;}

            if(c2==n-1) break;

            if(f1==-1 && f2==-1) {
                fg=-1; break;
            }
        }
        if(fg==-1) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }


    return 0;
}