#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;

ll nc2(ll n){
    
    return n * (n-1) / 2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        vector<ll> v;
        for(auto i=0;i<n;i++){
            ll x ; cin >> x;
            v.push_back(x);
        }
        vector<ll> df;
        for(ll i=0;i<n;i++){
            df.push_back(v[i] - (i+1)); // differnce between element and its index
        }
        map<ll , ll> mp;
        for(ll i=0;i<n;i++){
            mp[df[i]]++;
        }
        ll ans=0;
        // now range of df[i] is 1-n to n-1
        for(ll i=1-n;i<=n-1;i++){
            if(mp[i]>1){
                ans+= nc2(mp[i]); // bcoz in every pair j>i
            }
        }
        cout << ans << '\n';
    }



    return 0;
}