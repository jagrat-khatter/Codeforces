#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
bool comparator(pair<pair<ll,ll> , ll> a, pair<pair<ll,ll> , ll> b){
    if(a.second != b.second) return a.second <= b.second ;
    else{
        if(a.first.first != b.first.first) return a.first.first <= b.first.first;
        else {
            if(a.first.second != b.first.second)  return a.first.second >= b.first.second;
            else return false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        vector<pair<pair<ll,ll> , ll>> v;
        for(ll i=0;i<n;i++){
            ll li,ri,rli; cin >> li >> ri >> rli;
            v.push_back({{li,ri} , rli});
        }
        sort(v.begin() , v.end() , comparator);
        for(ll i=0;i<n;i++) {
            ll li=v[i].first.first,ri=v[i].first.second,rli=v[i].second;
            if(k>=li && k<=ri && rli > k) k=rli;
        }

        cout << k << '\n'; 
    }
    
    
    return 0;
}