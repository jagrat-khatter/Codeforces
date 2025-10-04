#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
        ll n,m ; cin >> n >> m;
        set<pair<ll,ll>> sp;
        map<ll,set<ll>> mp;
        map<ll,ll> sm;
        while(m--){
            ll a,b; cin >> a >> b; mp[a].insert(b); mp[b].insert(a);
            sp.insert({a,b});
            sm[a] = (sm[a]%MOD + b)%MOD;
            sm[b] = (sm[b]%MOD + a)%MOD;
        }
        // cout << sm[1] << ' ' << sm[2]<<' ' << sm[3]<<' ' << sm[4] <<'\n' ;
        ll ans=1;
        for(auto i : sp){
            ll p = (sm[i.first] - i.second + MOD)%MOD;
            ll q = (sm[i.second] - i.first + MOD)%MOD;

            if((mp[i.first].size() != mp[i.second].size()) || (p!=q)) {ans=0; break;}
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }




    return 0;
}