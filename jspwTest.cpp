#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0)  return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    
    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ld a=3.3450989485435;
    cout << fixed << setprecision(15) ;

    ld l=0 , r=1e7 + 1;
    ll n , k; cin >> n >>k;
    vector<ld> v(n); for(auto & i : v) cin >> i;

    for(ll i=1;i<=50;i++){
        ld m = (l+r)/2;
        ll ans = 0;
        for(auto j : v){
            ans += (ll)(j/m);
        }
        if(ans>=k) l=m;
        else r=m;
    }
    cout << l << '\n' ;

    


    return 0;
} 