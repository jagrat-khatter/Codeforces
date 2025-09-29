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
    else return b*value*value;
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
        ll n; cin >> n;
        vector<ll> v(n);
        set<ll> s; map<ll,ll> mp;
        bool ans = true;
        for(auto &i : v) {cin >> i;s.insert(i); mp[i]++;}
        for(ll i=0;i<n;i++){
            mp[v[i]]--;
            if(mp[v[i]] == 0) s.erase(v[i]);
            ll x = 2*v[i] - 1;
            auto it = s.upper_bound(x);
            // for(auto j : s)  cout << j << ' ';
            // cout << '\n';
            if(it != s.end()) {ans=false ; break;}
        }

        cout << ((ans==true)? "YES" : "NO") << '\n';

    }



    return 0;
}