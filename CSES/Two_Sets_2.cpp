#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD  = 1e9 + 7;
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
ll ans=0;
ll solve(ll n,ll sum ,vector<vector<ll>>& dp){
    //cout << n << ' ' << sum << '\n' ;
    if(sum<0 || n<0) return 0;
    else if(sum==0){
        return 1;
    }
    if(n * (n+1) / 2 < sum) return 0;

    if(dp[n][sum]!=-1) return dp[n][sum]%MOD;
    
    ll ans1 = solve(n-1 , sum , dp);
    ll ans2 = solve(n-1 , sum-n , dp);
    dp[n][sum] = (ans1%MOD + ans2%MOD)%MOD;

    return dp[n][sum] ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    ll n; cin >> n; // on taking input 
    if(((n * (n+1)/2) % 2) !=0)  cout << 0 << '\n';
    else 
    {vector<vector<ll>> dp(n + 1, vector<ll>(n * (n + 1) / 4 + 1, -1)); // maximum sum for a set should be (n * (n+1) / 2) / 2
    ll res =  solve(n , n*(n+1) / 4 , dp);
    cout << (res * 500000004LL % MOD) << '\n';}



    return 0;
}