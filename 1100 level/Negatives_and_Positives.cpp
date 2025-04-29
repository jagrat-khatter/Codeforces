#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a, ll b)
{
    if(a>b) return b;
    else return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v;
        ll mn = lmax , sum=0 , nn=0; // for calculating the abs minimum , absolute sum , and number of negatives
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
            if(x<0) nn++;
            sum += abs(x);
            mn = min (mn , abs(x));
        }
        if(nn%2==0) cout << sum << '\n';
        else cout << sum-mn-mn << '\n';
    }

    return 0;
}