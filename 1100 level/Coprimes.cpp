#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll max(ll a , ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        map<ll , ll> mp;
        vector<pair<ll ,ll >> a; // first one will store the original index of the element second will store value
        for(ll i=n-1;i>=0;i--)
        {
            ll e=v[i];
            if(mp[e]==0){
                mp[e]++;
                a.push_back({i,e});
            } 
        }
        reverse(a.begin() , a.end()); // this array can have only 1000 elements 
        // now will find max of gcd of all pairs
        ll ans = -1;
        for(ll i=0;i<a.size();i++)
        {
            for(ll j=i;j<a.size();j++)
            {
                ll p = a[i].second , q = a[j].second;
                if( gcd(p,q)==1 )
                {
                    ans = max(ans , a[i].first+a[j].first+1+1);
                    //cout << i << ' ' << j << '\n';
                }
            }
        }
        cout << ans << '\n';

    }

    return 0;
}