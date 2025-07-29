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
ll max(ll a, ll b){
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
        ll n,k ; cin >> n >> k;
        vector<ll> v(n);
        for(auto &i :v) cin >> i ;
        ll prblm = 0 , ans=0;
        for(ll i=1;i<=k;i++){
            if(v[i]*2 <= v[i-1]) prblm ++;
        }
        //cout << prblm << '\n';
        if(prblm==0) ans++; // for the first subarray
        for(ll i=1;i<=n-k-1;i++){
            if(prblm && v[i-1] >= 2*v[i]) prblm --;
            if(v[i+k-1] >= 2 * v[i+k]) prblm ++;

            if(prblm==0) ans++;
        }

        cout << ans << '\n' ;
    }




    return 0;
}