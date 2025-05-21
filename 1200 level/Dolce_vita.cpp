#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;cin >> t;
    while(t--)
    {
        ll n,x; cin >> n >> x;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        sort(v.begin() , v.end());
        ll ct=0;
        for(ll i=0;i<n;i++){
            x -= v[i];
            if(x<0) break;
            ct += x/(i+1) + 1;
        }

        cout << ct << '\n' ;
    }



    return 0;
}