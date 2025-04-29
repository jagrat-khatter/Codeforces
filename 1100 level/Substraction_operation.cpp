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
        ll n , k ; cin >> n >> k;
        multiset<ll> s;
        for(ll i=0;i<n;i++)
        {
            ll x ; cin >> x;
            s.insert(x);
        }
        // now for every element in the set we'll search a element in set for which abs(e1 - e2)==k
        ll fg=0;
        for(auto &i : s)
        {
            ll e = i;
            if(s.find(e+k)!=s.end() || s.find(e-k)!=s.end())  {fg=1; break;}
        }
        if(fg==1) cout << "YES" <<'\n';
        else cout << "NO" << '\n';
    }


    return 0;
}