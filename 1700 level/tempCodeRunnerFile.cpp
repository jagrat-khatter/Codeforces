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

    ll n,h,l,r ; cin >> n >> h >> l >> r;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; v[i]=x;
    }

    vector<ll> dp(2000 + 1 , 0), curr(2000 + 1 , 0);
    for(ll i=0;i<=2000;i++){
        if(i>=l && i<=r) dp[i]=1;
    }// this is done for last index 

    for(ll id=n-1;id>=1;id--){
        for(ll k=0;k<=2000;k++){
            curr[k]=0;
            ll h1 = (k+v[id])%h;
            ll h2 = (k+v[id]-1+h)%h;
            
            if(h1>=l && h1<=r) curr[k] = max(curr[k] , 1 + dp[h1]);
            else curr[k] = max(curr[k] , dp[h1]);

            if(h2>=l && h2<=r) curr[k] = max(curr[k] , 1 + dp[h2]);
            else curr[k] = max(curr[k] , dp[h2]);
        }
        swap(dp , curr);
    }

    cout << dp[0] << '\n' ;



    return 0;
}