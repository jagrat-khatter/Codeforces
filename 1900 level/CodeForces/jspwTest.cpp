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
        ll n,W; cin >> n >> W;
        vector<ll> w(n+1),v(n+1);
        for(ll i=1;i<=n;i++){
            ll p,q; cin >> p >> q;
            w[i] = p; v[i] = q;
        }

        vector<ll> dp(W+1 , 0),curr(W+1 , 0);

        for(ll id=1;id<=n;id++){
            for(ll sum=W;sum>=1;sum--){

                curr[sum] = dp[sum];
                if(sum-w[id] >= 0) curr[sum] = max(curr[sum] ,v[id] + dp[sum-w[id]]);
                if(curr[sum]==0) break;
            }
            cout << id << '\n' ;
            for(auto j : curr) cout << j << ' ';
            cout << '\n' ;
            swap(dp , curr);
        }
        cout << dp[W] ;
    }




    return 0;
}