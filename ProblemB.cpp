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
        ll n,x; cin >> n >> x;
        vector<ll> ans;
        for(ll i=0;i<n;i++){
            if(i!=x) ans.push_back(i);
        }

        if(x!=n) ans.push_back(x);
        for(auto i : ans) cout << i  <<  ' ';
        cout << '\n';
    }


    return 0;
}