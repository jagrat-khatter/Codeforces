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
        ll n; cin >> n ;
        vector<ll> v(n); for(auto & i : v) cin >> i;
        vector<ll> v1 , v2;
        ll fg=0;
        for(ll i=0;i<n;i++){
            if(v[i]<i) fg=1;
            if(!fg) v1.push_back(1);
            else v1.push_back(0);
        }
        reverse(v.begin() , v.end()); fg=0;
        for(ll i=0;i<n;i++){
            if(v[i]<i) fg=1;
            if(!fg) v2.push_back(1);
            else v2.push_back(0);
        }
        reverse(v2.begin() , v2.end());

        ll ans=0;
        for(ll i=0;i<n;i++){
            if(v1[i]==1 && v2[i]==1) {ans=1; break;}
        }
        if(ans) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

 
    return 0;
}