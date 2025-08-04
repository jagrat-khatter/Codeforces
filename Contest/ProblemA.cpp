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

    ll t; cin >> t;
    while(t--){
        ll x; cin >> x;
        vector<ll> v;
        for(ll i=1;i<=1e11+1;i=(2*i)+1){
            v.push_back(i);
        }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n' ;
        ll id=0;

        for(ll i=0;i<v.size();i++){
            id=i;
            if(v[i]  >=  x) break;
        }
        //cout << id << '\n';

        cout << 2*(id+1) + 1 << '\n' ;
    }

    

    return 0;
}