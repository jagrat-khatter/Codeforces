#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0)  return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll ans=0;
ll check(ll m, ll n){
    ll ct=0;
    for(ll i=1;i<=n;i++){
        if(m/i<=n) ct += m/i;
        else ct += n;

        if(m/i ==0 ) break;
    }

    return ct;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        ll l=1-1 , r=(n*n)+1;
        ll median =((n*n)+1) / 2 ;
        while(r-1 > l){
            ll mid = (l+r)/2;

            if(check(mid,n)<median) l=mid;
            else r=mid;
        }

        cout << r << '\n' ;
    }


    return 0;
}