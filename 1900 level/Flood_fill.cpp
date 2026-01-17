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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=1;i<=n;i++){
            ll x; cin >> x;
            if(i==1) v.push_back(x);
            else if(v[v.size()-1] != x) v.push_back(x);
        }

        vector<ll> vr;
        for(ll i=v.size()-1;i>=0;i--){
            vr.push_back(v[i]);
        }
        
        // now we need to find longest common subsequnce in this 
        // for(auto j :  v) cout << j << ' ';
        // cout << '\n';

        // for(auto j : vr) cout << j << ' ';
        // cout << '\n' ;

        ll sz = v.size();
        vector<vector<ll>> dp(sz+1 , vector<ll> (sz+1 , lmin));
        if(v[1-1]==vr[1-1]) dp[1][1]=1;
        else dp[1][1]=0;
        for(ll i=1;i<=sz;i++){
            for(ll j=1;j<=sz;j++){
                if(i==1 && j==1) continue;

                if(v[i-1]==vr[j-1]){
                    dp[i][j] = 1 ;
                    if(i-1 && j-1) dp[i][j]+= dp[i-1][j-1];
                }
                else {
                if(i-1) dp[i][j] = max(dp[i][j] , dp[i-1][j]);
                if(j-1) dp[i][j] = max(dp[i][j] , dp[i][j-1]);
                }

                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
            }
        } 

        cout << sz - ((dp[sz][sz]+1)/2) << '\n';
        
    }





    return 0;
}