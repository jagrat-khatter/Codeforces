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
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    vector<ll> ans;
    ll d; cin >> d; // Number of days
    while(d--)
    {
        ll c; cin >> c;
        ll l= 0-1 , r=v.size()-1+1;
        while(r-1>l)
        {
            ll mid=(l+r)/2;
            if(v[mid]<=c) l=mid;
            else r=mid;
        }
        ans.push_back(l+1);
    }
    for(ll i=0;i<ans.size();i++)
    {
        cout << ans[i] << '\n' ;
    }


    return 0;
}