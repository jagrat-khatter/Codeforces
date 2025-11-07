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
    if(b==0) return 1;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ll> dp(4+1 ,0),curr(4+1 ,0); 
        dp[4]=1;
        dp[2]=dp[3]=dp[1]=0;
        for(ll id=n;id>=1;id--){
            curr[4]=  ((dp[1] + dp[2])%MOD + dp[3])%MOD;
            curr[3]=  ((dp[4] + dp[2])%MOD + dp[1])%MOD;
            curr[2]=  ((dp[4] + dp[3])%MOD + dp[1])%MOD;
            curr[1]=  ((dp[4] + dp[3])%MOD + dp[2])%MOD;
            swap(dp , curr);
        }
        cout << dp[4] << '\n';
    }



    return 0;
}