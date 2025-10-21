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
    else return gcd(b  ,a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(n);
    for(auto &i : v) cin >> i;
    // parity of n-1 even or odd
    ll prt = (n-1)%2;
    vector<vector<ll>> dp(n , vector<ll> (n , 0));


    for(ll l=n-1;l>=0;l--){
        for(ll r=0;r<=n-1;r++){
            if(l<=r){
                ll prt2 = (l+r)%2;
                if(l==r){
                     // parity is same as of initial then this will contribute to player1
                    if(prt2 == prt) dp[l][r] = v[l]; // else dp[l][r] will remain 0 
                }
                else {

                    if(prt == prt2) dp[l][r] = max(dp[l+1][r] + v[l] , dp[l][r-1]+v[r]);
                    else dp[l][r] = min(dp[l+1][r] , dp[l][r-1]);
                }
                //cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
            
            }
        }
    }

    cout << dp[0][n-1] << '\n' ;



    return 0;
}