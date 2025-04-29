#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; cin >> n;
    map<ll ,ll> mp;
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        mp[x]++;
    }
    // now map stores the frequency of the elements from 1-1000
    ll ans = lmin;
    for(ll i=1;i<=1000;i++)
    {
        if(mp[i]>ans) ans = mp[i];// this will store the max frequency of a element
    }

    if(n%2==0 && ans<=(n/2)) cout << "YES" ;
    else if(n%2!=0 && ans<=(n/2) + 1) cout << "YES" ;
    else cout << "NO" ;


    return 0;
}