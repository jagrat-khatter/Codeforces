#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a , ll b){
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        map<ll ,ll> mp;
        vector<set<ll>> v;
        set<ll> uq; // this set will store all the unique elements 
        for(ll i=0;i<n;i++){
            ll m; cin >> m;
            v.push_back({});
            for(ll j=0;j<m;j++){
                ll x; cin >> x;
                mp[x]++;
                v[i].insert(x);
                uq.insert(x);
            }
        }
        ll ans =0;
        for(auto i : uq){ // now if this unique element does not have to be in the final s 
            ll e = i;
            set<ll> z;
            for(ll j=0;j<n;j++){
                if(v[j].find(e) == v[j].end()){
                    for(auto k : v[j]) z.insert(k);
                }
            }
            ans = max(ans , z.size());
        }
        cout << ans << '\n';
    }



    return 0;
}