#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9+7;
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
vector<ll> dp(1e5+1 , -1);
ll solve(ll n ,const ll& k){
    if(n<k) return 1;
    if(dp[n]!=-1) return dp[n]%MOD;
    

    dp[n] = (solve(n-k , k)%MOD+ solve(n-1 , k)%MOD)%MOD;
    return dp[n];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp , -1 , sizeof dp) ;
    // memset will not work other than 0 or -1
    ll t , k; cin >> t>> k;
    vector<ll> preComp; preComp.push_back(0);
    for(ll i=1;i<=1e5;i++){
        preComp.push_back(solve(i , k));
    }
    // now we'll make a vector for prefix sum 

    vector<ll> pf ;pf.push_back(0);
    for(ll i=1;i<preComp.size();i++){
        pf.push_back(pf[i-1]+preComp[i]);
    }
    
    
    while(t--){
        ll a ,b ; cin >> a >> b;
        ll ans=pf[b] - pf[a-1] ;
        
        cout << ans%MOD << '\n' ;
        // we have not used ((pf[b] - pf[a-1])%MOD + MOD) % MOD bcoz pf[b] > pf[a-1]
        // why we applied %MOD on (pf[b] - pf[a-1])
        // bcoz if (pf[b] - pf[a-1]) = 0-2*MOD then ans = 0+ MOD % MOD
        // else we had (0 - 2*MOD + MOD ) % MOD = -MOD % MOD;
    }




    return 0;
}