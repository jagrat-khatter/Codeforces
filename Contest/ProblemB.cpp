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
        vector<ll> v;
        for(ll i=1;i<=n;i++){
            ll x;cin >> x; if(x!=0) v.push_back(x);
        }

        // suppose we increase all the elements by 1
        if(!v.size()) {cout << 0 << '\n'; continue;}
        ll ct=0;
        for(auto j : v){
            ct += (j-1);
        }

        if(ct>=(n-1)) cout << v.size() << '\n';
        else cout << v.size() - (n-1-(ct)) << '\n' ;
    }



    return 0;
}