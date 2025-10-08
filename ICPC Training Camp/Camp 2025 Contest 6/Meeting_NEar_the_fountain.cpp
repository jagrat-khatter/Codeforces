#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
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

    ll t;t=1;

    while(t--){
        ld n,tm; cin >> n >> tm;
        ld m; cin >> m;
        ld x,y; cin >> x>> y;

        ld m1 = (m/(x*60)) , m2 = ((n-m)/(y*60)) ;

        
        //cout << m1 << ' ' << m2 << '\n';
        if(m1+m2 <= tm)  cout << 0 << '\n';
        else if(m1+m2 - (ll)(m1+m2) != (ld)0) cout << (ll)(m1+m2+1) - tm << '\n';
        else cout << (ll)(m1+m2) - tm << '\n';
    }




    return 0;
}