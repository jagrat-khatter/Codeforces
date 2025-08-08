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
        ll n; cin >> n;
        vector<ll> v(n);
        ll ck=0;
        ll na=-1;
        for(auto &i : v) {cin >> i;if(i==0) ck=1;if(i!=0 && i!=-1) na=i;}
        if(ck) {cout << "NO" << '\n'; continue;}
        ll ans=1;

        for(ll i=0;i<n;i++){
            if(v[i]!=-1 && v[i]!=na){
                ans=0; break;
            }
        }

        if(ans) cout << "YES" << '\n';
        else cout << "NO" << '\n' ;
    }

    

    return 0;
}