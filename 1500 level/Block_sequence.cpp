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
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }

        vector<ll> dp(n+1);
        for(ll id=n;id>=1;id--){
            ll p1,p2;
            if(v[id]<n-id) p1=dp[id+v[id]+1];
            else if(v[id]==n-id) p1=0;
            else p1=n-id+1;

            if(id!=n) p2 = 1 + dp[id+1];
            else p2=lmax;

            //cout << id << ' ' << p1 << ' '<< p2 << '\n' ;

            dp[id] = min(p1 , p2);
        }

        cout << dp[1]  << '\n';
    }




    return 0;
}