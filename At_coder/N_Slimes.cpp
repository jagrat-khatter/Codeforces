#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll sum(ll i,ll j , vector<ll> pf){
    return pf[j] - pf[i-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll n; cin >> n;
    vector<ll> v(n+1) , pf(n+1 , 0);

    for(ll i=1;i<=n;i++){
        ll x; cin >> x; v[i]=x;
        pf[i] = pf[i-1] + x;
    }

    vector<vector<ll>> dp(n+1 , vector<ll> (n+1 , 0));

    for(ll sz=0;sz<n;sz++){
        for(ll i=1;i<=n-sz;i++){
            ll j = i+sz;
            if(i==j) dp[i][j] = 0;
            else {
                dp[i][j] = lmax;
                for(ll k=i;k<j;k++){
                    ll tmp = sum(i , j, pf);
                    tmp += (dp[i][k] + dp[k+1][j]);// we are sure that dp[i][k] and dp[k+1][j] exist
                    //beacuse their sz is small 

                    dp[i][j] = min(dp[i][j] , tmp) ;
                }
            }

            //cout << i <<' ' << j << ' ' << dp[i][j] << '\n' ;
        }
    }

    cout << dp[1][n] << '\n';



    return 0;
}