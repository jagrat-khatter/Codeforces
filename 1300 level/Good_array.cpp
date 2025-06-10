#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; cin >> n;
    vector<ll> v(n);
    ll sum=0;
    set<ll> s;
    map<ll , ll> mp;
    for(auto &i : v) {cin >> i;sum += i; s.insert(i);mp[i]++;}
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        ll e=v[i];
        if(mp[e]-1 == 0) {s.erase(e);}
        ll mx = *(--s.end());
        if(sum-e-mx == mx) {ans.push_back(i+1);}


        if(mp[e]-1 == 0 ) {s.insert(e);} 
    }

    cout << ans.size() << '\n';
    for(auto i : ans) cout << i<< ' ';



    return 0;
}