#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll power(ll b ,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll solve(ll id, ll k, ll lvl, vector<set<ll>> &dpSets, vector<vector<ll>> &memo) {
    if(lvl == k) return 1;

    ll count=0;
    if(memo[id][lvl] != -1) return memo[id][lvl];
    else{
        for(auto i : dpSets[id]){
            count += (solve(i , k , lvl+1 , dpSets , memo) % (1000000007));
            count = count % (1000000007);
        }
    }

    memo[id][lvl] = (count % (1000000007));
    return (count%(1000000007));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    ll n,k; cin >> n >> k;
    vector<set<ll>> dp(n+1);
    for(ll id=1;id<=n;id++){
        ll ct=id;
        while(ct<=n){
            dp[id].insert(ct);
            ct+=id;
        }
    }// sets are already made
    ll ans=0;
    vector<vector<ll>> memo(n+1, vector<ll>(k+1, -1));
    for(ll j = 1; j <= n; j++){
        ans += (solve(j, k, 1, dp, memo) % (1000000007));
        ans = ans % (1000000007);
    }

    cout << ans% (1000000007) << '\n';

    return 0;
}