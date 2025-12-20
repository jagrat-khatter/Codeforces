#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
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
        ll n; cin >> n;
        vector<vector<ll>> v(n+1 , vector<ll> (n+1));
        ll ct=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                v[i][j] = ct;
                ct++;
            }
        }

        ll ans = lmin;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                ll temp = v[i][j];
                if(i-1 >= 1) temp+= v[i-1][j];
                if(i+1 <= n) temp+= v[i+1][j];
                if(j+1 <=n) temp += v[i][j+1];
                if(j-1 <= n) temp += v[i][j-1];
                ans = max(temp , ans);
            }
        }

        cout << ans << '\n' ;

    }



    return 0;
}