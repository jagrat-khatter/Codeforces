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
    return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ;t=1;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> dp(n+1 , 0),curr(n+1 , 0);
        for(ll tm=1;tm<=n;tm++){
            dp[tm]=1;
        }
        for(ll id=2*m-1;id>=1;id--){
            for(ll tm=1;tm<=n;tm++){
                curr[tm]=0;
                for(ll j=tm;j<=n;j++){
                    curr[tm] += dp[j];
                    curr[tm]%= MOD;
                }
            }

            swap(dp , curr);
        //     for(auto j : dp) cout << j << ' ';
        // cout << '\n' ;
        }
        ll ans=0;
        for(auto j : dp){
            ans = (ans+ j) % MOD;
        }
        cout << ans << '\n' ;
        
    }


    return 0;
}