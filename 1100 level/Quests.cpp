#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll max(ll a , ll b)
{
    if(a>b) return a;
    return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , k ; cin >> n >> k;
        vector<ll> a,b;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            a.push_back(x);
        }
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            b.push_back(x);
        }
        ll sum=0,ans=INT_MIN , mx=INT_MIN;
        for(ll i=0;i<k;i++)
        {
            if(i<=n-1)
            {
                sum += a[i];
                mx = max(b[i] , mx);
                ans = max(ans , sum + (k-i-1)*mx);
            }
        }
        cout << ans << '\n' ;
    }
    

    return 0;
}