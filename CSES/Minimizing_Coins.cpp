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
    return value*value*((e%2==0) ? b : 1);
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
        ll n ,x; cin >> n >> x;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;

        
        vector<ll> dp(x+1  ,-1);
        dp[0]=0;
        for(ll sum=1;sum<=x;sum++){
            
            dp[sum] = lmax;
            for(auto c : v){
                if(sum-c >= 0){
                    ll e = dp[sum-c];
                    if(e>=0){
                        dp[sum] = min(e+1 , dp[sum]);
                    }
                }
            }
            if(dp[sum]==lmax) dp[sum]=-1; 
        }

        cout << dp[x] << '\n' ;
    }




    return 0;
}