#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b , a%b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin >> v[i];

        if(n==1) {cout << 0 << '\n' ; continue;}
        vector<ll> df;
        for(ll i=0;i<(n/2);i++)
        {
            ll x = abs(v[n-i-1] - v[i]) ;
            df.push_back(x);
        }
        
        ll ans; ans = df[0];
        for(ll i=1;i<df.size();i++)
        {
            ans = gcd(ans , df[i]);
        }
        cout << ans << '\n' ;
    }


    return 0;
}