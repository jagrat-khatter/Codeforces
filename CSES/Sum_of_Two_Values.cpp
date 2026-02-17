#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
void debug(const vector<ll> v){
    cerr << "[ ";
    for(auto  j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ,x; cin >> n>>x;
    vector<pair<ll,ll>> v;
    v.push_back({0,0});
    for(ll i=1;i<=n;i++) {
        ll x ;cin >> x; v.push_back({x,i});
    }

    sort(v.begin() , v.end());

    ll p1=1 , p2=v.size()-1 , ans=-1;
    while(p1<p2){
        ll sum = v[p1].first + v[p2].first ;
        if(sum>x) p2--;
        else if(sum<x) p1++;
        else {cout <<v[p1].second <<  ' ' << v[p2].second << '\n' ; ans=1 ; break;}
    }

    if(ans==-1) cout << "IMPOSSIBLE" << '\n' ;





    return 0;
}