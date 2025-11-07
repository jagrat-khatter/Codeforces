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

    ll n; cin >> n;
    vector<ll> dp(1e5 + 1 , 0);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; sum+= x;
        
        set<ll> s;
        for(ll j=0;j<=sum && i!=1;j++){
            if(dp[j]==1) s.insert(j+x);
        }
        dp[x]=1;
        for(auto j : s) dp[j]=1;
    }

    ll ct=0;
    for(ll i=1;i<=1e5;i++){
        if(dp[i]==1) ct++;
    }
    cout << ct << '\n';
    for(ll i=1;i<=1e5;i++){
        if(dp[i]==1) cout << i << ' ';
    }
    cout << '\n';


    return 0;
}