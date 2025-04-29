#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN; 
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin>> n;
        ll ne = n*(n-1) /2;
        vector<ll> v;
        set<ll> s; map<ll , ll> mp;
        for(ll i=0;i<ne;i++){
            ll x; cin >> x;
            v.push_back(x);
            mp[x]++;
            s.insert(x);
        }

        vector<ll> ans;
        for(ll i=0;i<n-1;i++){ // making till index n-2 bcoz at index n-1 requirement becomes 0
            ll rq = n-i-1;
            
            for(auto j : s){
                if(mp[j] >= rq){
                    ans.push_back(j);
                    mp[j] -= rq;
                    break;
                }
                
            }
        }
        ans.push_back(ans[n-2]);
        for(auto i : ans) cout << i << ' ';
        cout << '\n';

    }

    return 0;
}