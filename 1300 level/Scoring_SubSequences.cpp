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
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x; v.push_back(x);
            ll l=0-1 , r=v.size()-1+1;
            while(r-1>l)
            {
                ll mid = (l+r)/2;
                if(v[mid]<i+1-mid)  l = mid;      // true condition
                else    r = mid ; // false condition
            }
             cout << i+1-r<< ' ';
            // cout << l << ' ' << r << '\n';
        }

        cout << '\n';
    }



    return 0;
}