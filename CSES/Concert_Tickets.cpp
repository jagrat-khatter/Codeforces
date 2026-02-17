#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
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
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m ; cin >> n >> m;
    vector<ll> v(n+1);
    ordered_map mp;
    for(ll i=1;i<=n;i++){
        cin >> v[i];mp[v[i]]++;
    }

    ll ans=0;
    for(ll i=1;i<=m;i++){
        ll x; cin >> x;
        if(!mp.size()) {cout << -1 << '\n' ; continue;}
        auto it = (mp.upper_bound(x));
        

        if(it == mp.begin() && (it->first)>x) cout << - 1<< '\n';
        else {
            if(it!=mp.begin()) it--;
            ll e = (it)->first;
            cout << e<< '\n'; mp[e]--;
            if(mp[e]==0) mp.erase(e);
        }
    }
    
    
    



    return 0;
}