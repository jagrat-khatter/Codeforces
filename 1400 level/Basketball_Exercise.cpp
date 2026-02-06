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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // dp[i][1] = up until maximum sum of heights such that ahead we can take height from row1
    // dp[i][2] = up until maximum sum of heights such that ahead we can take height from row2

    // dp[i][1] = max(h2[i]+dp[i-1][2] , dp[i-1][1])
    // dp[i][2] = max(h1[i]+dp[i-1][1] , dp[i-1][2])


    ll n; cin >> n;
    vector<ll> a(n+1) , b(n+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=n;i++) cin >> b[i];
    vector<vector<ll>> dp(n+1 , vector<ll> (3 ,0));
    dp[1][1]=b[1];
    dp[1][2]=a[1];
    for(ll i=2;i<=n;i++){
        dp[i][1] = max(b[i]+dp[i-1][2] , dp[i-1][1]);
        dp[i][2] = max(a[i]+dp[i-1][1] , dp[i-1][2]);
    }

    cout << max(dp[n][1] , dp[n][2]);


    return 0;
}