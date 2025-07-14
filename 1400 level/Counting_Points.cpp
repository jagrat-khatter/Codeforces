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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        set<ll> xc;
        map<ll,ll> mp;
        vector<ll> xv(n),rv(n);
        for(auto &i : xv) cin >> i;
        for(auto &i : rv) cin >> i;

        for(ll i=0;i<n;i++){
            ll x=xv[i] , r = rv[i];
            for(double long j =x-r;j<=x+r;j++){
                xc.insert(j);
                double long yc = sqrt(r*r - (j-x)*(j-x));
                mp[j] = max(mp[j] , (ll)(yc));
            }
        }

        ll ans=0;
        for(auto i : xc){
            // cout << i << ' ' << mp[i]  << '\n';
            ans += 2 * mp[i] + 1;
        }
        

        cout << ans << '\n';
    }
    
    
    return 0;
}