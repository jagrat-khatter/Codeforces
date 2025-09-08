#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;
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
        vector<pair<ll ,ll>> v(n);
        for(ll i=0;i<n;i++) cin >> v[i].first;
        for(ll i=0;i<n;i++) cin >> v[i].second;

        sort(v.begin() , v.end());
        vector<ll> pfb;
        vector<ll> a;
        for(ll i=0;i<n;i++){
            a.push_back(v[i].first);

            if(i==0) pfb.push_back(v[0].second);
            else pfb.push_back(pfb[i-1] + v[i].second);
        }
        ll l=0-1 , r=1e9 + 1;
        // for(auto j : a) cout << j << ' ';
        // cout << '\n' ;
        
        // for(auto j : pfb) cout << j << ' ';
        // cout << '\n' ;
        while(r-1 > l){
            ll m=(l+r) / 2;
            // now find the last element in a which is <= m
            auto it = upper_bound(a.begin() , a.end() , m);
            ll id = distance(a.begin() , it) - 1;
            ll time_petya ;
            if(id!=-1) time_petya = pfb[n-1] - pfb[id];
            else time_petya = pfb[n-1];
            //cout << m << ' ' << time_petya << '\n';

            if(time_petya<=m) r=m;
            else l=m;
        }
        cout << r << '\n' ;
    }


    return 0;
}