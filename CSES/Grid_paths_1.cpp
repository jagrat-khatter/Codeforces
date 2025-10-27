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
    else return gcd(b ,a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<vector<char>> v(n+1 , vector<char> (n+1));
    for(ll i=1;i<=n;i++){
        
        for(ll j=1;j<=n;j++){
            char x; cin >> x;
            v[i][j] = x;
            //cout << v[i][j] << '\n';
        }
    }
    vector<vector<ll>> dp(n+1 , vector<ll> (n+1, 0));

    if(v[n][n] != '*') dp[n][n]=1;
    for(ll i=n;i>=1;i--){
        for(ll j=n;j>=1;j--){
            if(v[i][j]!='*'){ // if the point itself if not the obstacle
                if(i+1<=n && v[i+1][j] != '*') dp[i][j] += dp[i+1][j];
                dp[i][j] %= MOD;
                if(j+1<=n && v[i][j+1] != '*') dp[i][j] += dp[i][j+1];
                dp[i][j] %= MOD;
                //cout << i << ' ' << j <<' ' << dp[i][j] << '\n';
            }
        }
    }

    cout << dp[1][1] ;


    return 0;
}