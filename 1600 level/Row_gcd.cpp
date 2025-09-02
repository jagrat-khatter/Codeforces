#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    ll n,m; cin >> n >> m;
    vector<ll> vn(n) , vm(m);
    for(auto &i : vn) cin >> i;
    sort(vn.begin() , vn.end());
    for(auto &i : vm) cin >> i;

    ll gdf;
    for(ll i=1;i<n;i++){
        if(i!=1) gdf = gcd(vn[i] - vn[i-1] , gdf);
        else gdf = vn[i] - vn[i-1];
    }
    for(auto i : vm){
        cout << gcd(i+vn[0] , gdf) << ' ';
    }
    cout << '\n' ;




    return 0;
}