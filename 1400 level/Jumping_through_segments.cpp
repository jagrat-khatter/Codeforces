#include <bits/stdc++.h>
using namespace std;
using ll = long  long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);

    if(! e%2) return value * value ;
    else return value * value * b;
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

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> v(n);
        for(auto &j : v) cin >> j.first >> j.second;
        
        
        ll l=0-1, r=1e9+1;
        while(r-1 > l){
            ll mid = (l+r)/2 ;
            ll k = mid;
            ll leftk = 0 , rightk = k , fg=0;
            for(auto j : v){
                ll xc = j.first , yc = j.second;
                if(rightk < xc || leftk > yc) {fg=1; break;}

                // Our player should land in this range only 
                leftk = max(xc,leftk);
                rightk = min(yc,rightk);
                
                // Making the new range of possible landing 
                leftk = max(0LL , leftk-k);
                rightk = rightk + k;
            }
            if(fg) l = mid;
            else r = mid;
        }

        cout << r << '\n';
    }


    return 0;
}