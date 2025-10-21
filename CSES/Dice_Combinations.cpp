#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}

ll ans=0;
ll helper(ll n , vector<ll>& dp){
    // cout << n << '\n';
    if(n==0) {return 1;} // sometimes -ve index might come then it should not go to dp[n] it might get garbage value 

    if(dp[n] != -1) return (dp[n]%MOD); // number of ways can never be -ve so lets make this base case

    dp[n]=0;
    for(ll k=1;k<=6 && n>=k;k++){
        dp[n] += (helper(n-k , dp));
        dp[n] = (dp[n]%MOD);
    }

    return (dp[n]%MOD);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> dp(n + 1 , -1);
    cout << helper(n , dp);


    return 0;
}