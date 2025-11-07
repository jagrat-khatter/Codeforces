#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k,z; cin >> n >> k >> z;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            ll x; cin >> x; v[i]=x;
        }

        vector<ll> pf(n+1 , 0);
        for(ll i=1;i<=n;i++){
            pf[i] = pf[i-1] + v[i];
        }

        ll ans = lmin;
        for(ll i=1;i<=k+1;i++){
            ll usd = i-1 , tmp = pf[i];
            ll lf = min((k-usd)/2 , z);
            ll rg = k - usd - lf;
            
            ll osc = min(lf , rg);// either rf will be equal or 1 greater than lf
            tmp += osc * (v[i] + v[i+1]);
            rg -= osc;
            tmp += (pf[i+rg] - pf[i]);
            ans = max(ans , tmp) ;
        }
        cout << ans << '\n' ;
    }



    return 0;
}