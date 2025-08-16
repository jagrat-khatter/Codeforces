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
        set<ll> s; map<ll , ll> mp;
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            s.insert(x); mp[x]++;
        } 
        for(auto i : s){
            ll e= mp[i];
            ans += e / 2;
        }
        cout << ans << '\n' ;
    }

    

    return 0;
}