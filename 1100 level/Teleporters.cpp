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
        ll n,c; cin >> n>> c;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x+i+1);
        }
        sort(v.begin() , v.end());
        ll id=-1;
        for(ll i=0;i<n;i++)
        {
            if(c-v[i]>=0) {
                id=i;
                c -= v[i];
            }
            else break;
        }
        cout << id+1 << '\n';
    }



    return 0;
}