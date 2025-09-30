#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        vector<ll> v(n); for(auto & i : v) cin >> i;
        vector<ll> cc; cc.push_back(0);ll ct=1;
        while(cc[cc.size()-1] <= 1e12){ // we'll maximum addition we should offer is 2*1e9
            ct*= 2;
            cc.push_back(ct-1);
        }

        ll mx = lmin , ans=0;
        for(ll i=0;i<n;i++){
            mx = max({mx , v[i]});
            ll inc = mx - v[i];

            ll l=0-1 , r=cc.size()-1+1;
            while(r-1 > l){
                ll mid = (l+r)/2;
                if(cc[mid]<inc) l=mid;
                else r=mid;
            }
            ans = max(ans , r);
        }

        cout << ans << '\n';
    }




    return 0;
}