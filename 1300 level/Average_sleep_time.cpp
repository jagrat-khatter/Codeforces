#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    ll t; t=1;
    while(t--)
    {
        ll n,k ; cin >> n >> k;
        vector<ll> v(n);
        for(auto & i: v) cin >> i;
        vector<ll> pf;
        for(ll i=0;i<n;i++){
            if(i==0) pf.push_back(v[i]);
            else pf.push_back(pf[i-1] + v[i]);
        }
        long double ans =0;
        ll ct=0;
        for(ll i=k-1;i<n;i++){
            if(i==k-1) ans += pf[i];
            else ans += pf[i] - pf[i-(k-1)-1];

            ct++;
        }

        cout << ans/ct << '\n';

    }




    return 0;
}