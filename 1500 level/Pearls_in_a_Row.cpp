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

    ll t; t=1;
    while(t--){
        ll n; cin >> n; vector<ll> v(n);
        for(auto & i : v) cin >> i;
        set<ll> s;ll ptr=0 , ans=0;
        vector<pair<ll,ll>> vp;
        for(ll i=0;i<n;i++){
            if(s.find(v[i]) != s.end()){
                vp.push_back({ptr+1 , i+1});
                ptr = i+1;
                s.clear(); ans=1;
            }
            else s.insert(v[i]);
        }
        if(!ans) cout << -1 << '\n';
        else {
            cout << vp.size() << '\n';
            for(ll j=0;j<vp.size();j++) {
                if(j==vp.size()-1){
                    cout << vp[j].first << ' ' << n << '\n';
                }
                else cout << vp[j].first << ' ' << vp[j].second << '\n';
            }
        }
    }



    return 0;
}