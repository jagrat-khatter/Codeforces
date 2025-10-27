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
    if(b==0) return 1;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,W; cin >> n >> W;
        vector<ll> w(n+1),v(n+1);
        ll mn,mx;
        for(ll i=1;i<=n;i++){
            ll p,q; cin >> p >> q;
            w[i] = p; v[i] = q;
        }

        vector<ll> dp(1e5+1, 0),curr(1e5+1, 0);
        
        for(ll pf=0;pf<=1e5;pf++){
            if(v[n]>=pf) dp[pf]=w[n];
            else dp[pf]=lmax;
        }
        // for(auto j : dp) cout << j << ' ';
        //     cout << '\n';
        for(ll id=n-1;id>=1;id--){
            for(ll pf=1e5;pf>=0;pf--){
                curr[pf]=lmax;
                if(dp[pf]!=lmax) curr[pf]=min(curr[pf] , dp[pf]);
                if(pf-v[id] <= 0) curr[pf]=min(curr[pf] , w[id]);
                if(pf-v[id]>0 && dp[pf-v[id]]!=lmax) curr[pf]=min(curr[pf] , w[id] + dp[pf-v[id]]);
                
            }

            // for(auto j : curr) cout << j << ' ';
            // cout << '\n';
            swap(dp , curr);
        }

        for(ll sum=0;sum<1e5;sum++){
            if(dp[sum+1]>W) {cout << sum << '\n'; break;}
        }
        if(dp[1e5]<=W) cout << 1e5 << '\n';
        

    }




    return 0;
}