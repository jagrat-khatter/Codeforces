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

    cout << fixed << setprecision(11) ;
    ll n; cin >> n;
    vector<ld> v(n);
    for(auto &i : v) cin >> i;
    vector<ld> dp(n+1) , curr(n+1); // for storing probabilities of getting x tails 
    dp[0]=1-v[0];dp[1]=v[0];
    for(ll id=1;id<n;id++){ // following zero based indexing here 
        curr[0]=1-v[id];
        ld ph = v[id];
        ld pt = 1-v[id];
        //cout << ph << ' ' << pt << '\n';
        curr[0] = pt*dp[0];
        for(ll hd=1;hd<=id+1;hd++){// number of heads possible for a particular index
        
            curr[hd] = ph*(dp[hd-1]);
            if(hd<=id-1+1) curr[hd] += pt*(dp[hd]);
        }

        // for(auto j : curr) cout << j << ' ';
        // cout << '\n';

        swap(dp , curr);
    }
    ld ans=0;
    for(ll i=0;i<dp.size();i++){
        ll h=i , t=n-i;
        if(h>t) ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}