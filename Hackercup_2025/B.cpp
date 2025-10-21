#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value  = power(b , e/2);
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
    ll cs=0;
    while(cs<t){
        cs++;
        ll n; cin >> n;
        vector<ll> v(n);
        ll ans=0;

        for(auto &i : v) cin >> i;
        for(ll i=1;i<v.size();i++){
            ans = max(ans , abs(v[i] - v[i-1]));
        }

        cout << "Case #" << cs << ": " << ans << '\n';
        
    } 





    return 0;
}