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
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];

        vector<pair<ll,ll>> dp(n+1 , {lmax ,lmax}); // dp[i].first->Me and dp[i].second->Friend
        dp[1].second=v[1];
        if(n>1) dp[2].second=v[1]+v[2];
        dp[1].first=imax;
        if(n>1) dp[2].first=dp[1].second;
        // dp[i].first = if at ith index my turn ends then minimum number of skip points used by 
        // my friend up until 1->i th index
        // dp[i].second = if at ith index my friends turn ends then minimum number of skip points used by 
        // my friend up until 1->i th index
        for(ll i=3;i<=n;i++){
            
            dp[i].first = min(dp[i-1].second , dp[i-2].second);
            // caution on dp[i-2] + v[i-1] if i==3 and dp[1].first = lmax this might give overflow
            dp[i].second = v[i] + min(dp[i-1].first , dp[i-2].first + v[i-1]);
            // if friend chooses that my chance ends at i-2 then and my chance ends at i 
            // then he has to pay price of v[i-1] and v[i]
            // if friend chooses that my chance ends at i-1 then and my chance ends at i 
            // then he has to pay price of v[i]
            //cout << i <<' ' << dp[i].first << ' ' << dp[i].second << '\n' ;
        }

        cout << min(dp[n].first , dp[n].second) << '\n';
    }




    return 0;
}