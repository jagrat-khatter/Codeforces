#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin >> v[i];
        ll ct=0;
        for(ll i=0;i<n-1;i++) // we have no intent of taking last element as input
        {
            ll x = v[i];
            if(x==1) ct++;
            else break;
        }
        if(ct%2==0) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }



    return 0;
}