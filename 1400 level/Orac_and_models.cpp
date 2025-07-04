// Recursion for each number id we find how many number ids can be found such that s(i) < s(i+1)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll solve(map<ll ,ll>& mp ,ll id, ll n , vector<ll>& dp){
    if(dp[id] != -1) return dp[id];

    // first calculate all multiples of id that are less than equal to n
    set<ll> s;
    ll ct=id*2;
    
    while(ct<=n){
        //cout << ct << '\n';
        if(mp[ct] > mp[id]) s.insert(ct);
        ct+=id; // ct should be multiple of id 
    }
    //cout << id << '\n';
    // for(auto i : s) cout << i << '\n';
    ll ans=1;
    if(! s.empty()){
        ans=0;
        for(auto i : s){
            ans = max(ans , solve(mp , i , n , dp)+1) ;
        }
    }
    dp[id] = ans;
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll , ll> mp;
        for(ll i=1;i<=n;i++){
            ll x; cin >> x;
            mp[i] = x;
        }

        vector<ll> dp(n+1 , -1);
        ll ans =0;
        for(ll i=1;i<=n;i++){
            ans = max(ans , solve(mp , i , n , dp));
        }
        cout << ans << '\n';
    }
    
    

    return 0;
}