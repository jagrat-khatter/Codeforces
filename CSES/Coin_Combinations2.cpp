#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
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
        ll n,x; cin >> n >> x;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;

        vector<ll> dp(x+1 , 0);
        dp[0]=1;
        for(auto c : v){
            for(ll i=0;i<=x;i++){
                if(i-c>=0) dp[i] += dp[i-c];
                dp[i]%= MOD;
            }
        }

        cout << dp[x]%MOD << '\n' ;
    }




    return 0;
}