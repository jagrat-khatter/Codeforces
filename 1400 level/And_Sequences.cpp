#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;al
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a ;
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
        ll mn = lmax;
        for(auto &i : v) {cin >> i; mn = (mn & i);}
        //cout << mn << '\n' ;
        ll ct=0;
        for(ll i=0;i<n;i++){
            if(v[i] == mn) ct++;
        }
        if(ct<2) cout << 0 << '\n';
        else {
            ll ans = 1;
            for(ll j=ct;j>ct-2;j--){
                ans = ((ans % MOD) * (j % MOD)) % MOD;
            }

            for(ll j=1;j<=n-2;j++){
                ans = ((ans % MOD) * (j % MOD)) % MOD;
            }
            cout << ans << '\n' ;
        }
        
    }



    return 0;
}