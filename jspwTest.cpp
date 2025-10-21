#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){   
    if(a.second!=b.second) return a.second < b.second;
    else return a.first < b.first ;
}

ll helper(ll id , vector<ll>& dp , vector<ll>& v){
    if(id>=dp.size()) return 0;

    if(dp[id] != lmin) return dp[id];
    
    
    ll ans = 1;
    for(ll i=2*id;i<dp.size();i+=id){
        if(v[id] < v[i]) ans = max(ans , 1 + helper(i, dp,v));
    }

    return dp[id] = ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1) , dp(n+1 , lmin);

        v[0]=0;
        for(ll i=1;i<=n;i++){
            ll x; cin >> x;  v[i]=x;
        }

        
        ll ans=1;
        for(ll i=1;i<=n;i++){
            ans = max(ans , helper(i , dp , v));
        }

        cout << ans << '\n' ;
    }


    return 0;
}