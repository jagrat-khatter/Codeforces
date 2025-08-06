#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value= power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
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

    vector<ll> v;
    ll ct=1;
    while(ct<=1e18){
        v.push_back(ct);
        ct*= 2;
    }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll ans=0;
        for(auto j : v){
            ans += (n / j); // This represents the number of times this bit changed 
        }
        cout << ans << '\n' ;
    }




    return 0;
}