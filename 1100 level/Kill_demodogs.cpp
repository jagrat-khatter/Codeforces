#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9+7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll inv2 = (MOD+1)/2;
    ll inv3 = (MOD+2)/3;
    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n ;
        ll ans = 2022 * ((((((n)*(n+1))%MOD * (2*n+1)%MOD)%MOD * inv3)%MOD  -  (((n*(n+1))%MOD)*inv2)%MOD) + MOD)%MOD ;
        cout << ans << '\n' ;
    }
    
    
    return 0;
}