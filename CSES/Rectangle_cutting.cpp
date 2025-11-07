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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b; cin >> a >> b;
    vector<vector<ll>> dp(500+1 , vector<ll> (500+1 , lmax));


    for(ll i=1;i<=a;i++){
        for(ll j=1;j<=b;j++){
            if(i==j) dp[i][j]=0;
            else {
                dp[i][j] =lmax;
                //cout << i << ' ' << j << ' ' << dp[i][j] << '\n' ;
                for(ll l1=1;l1<=(i/2);l1++){
                    dp[i][j] = min(dp[i][j] , 1 + dp[l1][j] + dp[i-l1][j]);
                }
                for(ll l2=1;l2<=(j/2);l2++){
                    dp[i][j] = min(dp[i][j] , 1 + dp[i][l2] + dp[i][j-l2]);
                }
            
            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n' ;
        }
    }

    cout << dp[a][b] ;


    return 0;
}