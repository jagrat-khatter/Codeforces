#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    return gcd(b , a%b);
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
        vector<ll> v(n); for(auto & j : v) cin >> j;
        ll m; cin >> m;
        ll e=1;
        for(ll j=1;j<=m;j++) {
            ll x; cin >> x; e+= x;
        }
        if(e%n!=0) e = e%n;
        else e = n;
        cout << v[e-1] << '\n' ;
    }



    return 0;
}