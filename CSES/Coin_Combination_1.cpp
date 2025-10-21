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
ll tgt;
vector<ll> dp(1e6+1 , 0);// sum can be maximum 1e6
// initializing dp array with -1 
ll helper(ll sum,vector<ll>& v){
    if(sum==0) return 1;
    else if(sum<0) return 0;
    
    if(dp[sum]!=-1) return dp[sum];
    ll ans=0;
    for(ll i=0;i<v.size();i++){
        ans += ((helper(sum-v[i] , v)%MOD)%MOD);
        ans = ans%MOD;
    }

    return dp[sum] = ans%MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t ;t=1;
    while(t--){
        ll n,x; cin >> n >> x; tgt=x;
        vector<ll> v(n);
        
        for(auto &i : v) cin >> i;
        dp[0] = 1;

        for(ll sum=0;sum<=x;sum++){
            for(auto c : v){
                if(sum - c >= 0){
                    dp[sum] += dp[sum - c];
                    dp[sum] %= MOD;
                }
            }
        }

        cout << dp[x]%MOD ;

    }


    return 0;
}