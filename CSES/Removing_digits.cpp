#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> dp(n+1 , lmax);

    dp[0]=0;
    for(ll i=1;i<=9;i++){
        dp[i]=1;
    }
    for(ll i=10;i<=n;i++){
        set<ll> s;// this will have all the digits of i
        ll cp = i;
        while(cp){
            s.insert(cp%10);
            cp /= 10;
        }
         
        for(auto j : s){
            if(j!=0 && i-j>=0) dp[i] = min(dp[i] , 1 + dp[i-j]);
        }
    }

    // for(ll i=0;i<=27;i++){
    //     cout << dp[i] << ' ';
    // }

    cout << dp[n] << '\n' ;

    return 0;
}