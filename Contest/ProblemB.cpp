#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> fb;
    fb.push_back(1);
    fb.push_back(2);
    for(ll i=2;i<=11;i++){
        fb.push_back(fb[i-2]+fb[i-1]);
    }
    ll t; cin >> t;
    while(t--){
        ll n,m ; cin >> n >> m;
        
        ll sd1=fb[n-1] , sd2=fb[n-2];
            for(ll i=0;i<m;i++){
                ll w,l,h; cin >> w >> l >> h;
            ll fg=0;
            if(w>=sd1+sd2 || l>=sd1+sd2 || h>=sd1+sd2) fg=1;
            if(w<sd1 || l<sd1 || h<sd1) fg=0;
            cout << fg ;
        }
        cout << '\n' ;
    }

    

    return 0;
}