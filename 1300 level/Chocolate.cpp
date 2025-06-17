#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; cin >> n;
    vector<ll> v(n);
    
    for(auto &i : v) cin >> i;
    
    vector<ll> s;
    for(ll i=0;i<n;i++){
        if(v[i]==1) s.push_back(i+1);
    }
    if(s.size() == 0 ) {cout << 0 << '\n';}
    else {ll ans=1;
    for(ll i=1;i<s.size();i++){
        ans = (s[i] - s[i-1] ) * ans;
    }

    cout << ans << '\n';}

    return 0;
}