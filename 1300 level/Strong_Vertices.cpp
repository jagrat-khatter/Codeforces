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
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> a(n),b(n);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;

        vector<pair<ll ,ll >> v;
        for(ll i=0;i<n;i++)
        {
            v.push_back({a[i]-b[i] , i+1}); // first element stores the value of a[i] - b[i],
            // second element stores the value of index in one based indexing
        }
        // now sort the values in ascending order of a[i] - b[i]
        sort(v.begin() , v.end());
        ll e = v[n-1].first; // maximum value of a[i] - b[i] possible
        ll ct=0;
        for(ll i=n-1;i>=0;i--){
            //cout << v[i].first << '\n';
            if(v[i].first != e) break;
            ct++;
        }
        cout << ct << '\n';
        vector<ll> ans;
        for(ll i=n-1;i>=n-1-ct+1;i--){
            ans.push_back(v[i].second); // index saved of those elements
        }
        sort(ans.begin() , ans.end());
        for( auto I : ans) cout << I << ' ';
        cout << '\n';
    }




    return 0;
}