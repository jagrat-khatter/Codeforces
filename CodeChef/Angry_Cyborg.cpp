#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
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
        ll n,q; cin >> n >> q;
        vector<ll> v1(n+2);
        vector<ll> v2(n+2);
        while(q--){
            ll l,r;cin >> l >> r;
            v1[l]++;
            v1[r+1]--;
            ll diff=mod(l - 1);
            v2[l] -= diff;
            v2[r+1] += diff;
        }
        for(ll i=1;i<n+2;i++){
            v1[i] += v1[i-1]; // calculating prefix
        }
        for(ll i=1;i<n+2;i++){
            v2[i] += v2[i-1]; // calculating prefix
        }
        for(ll i=1;i<=n;i++){
            cout << i * v1[i] + v2[i] << ' ';
        }
        cout << '\n' ;

    }



    return 0;
}