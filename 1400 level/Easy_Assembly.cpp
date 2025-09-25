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

    ll n; cin >>n;
    set<ll> s;
    vector<vector<ll>> v;
    for(ll i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back({});

        for(ll j=0;j<x;j++){
            ll e; cin >> e;s.insert(e);
            v[v.size()-1].push_back(e);
        }
    }
    ll spt =0;
    map<ll,ll> mp;
    for(auto it = s.begin(); it != (--s.end());it++){
        auto nextIt = next(it);
        mp[*(it)] = *(nextIt);
    }
    //for(auto i : s) cout << i << ' ' << mp[i] <<'\n';
    for(auto i : v){
        for(ll j=0;j<i.size()-1;j++){
            if(i[j]>i[j+1]) spt++;
            else if(mp[i[j]] != i[j+1]) spt++;
        }
    }
    cout << spt  << ' ' << n + spt -1 << '\n';


    return 0;
}