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

    vector<ll> v;
    for(ll i=2;i<=1e9;i++){
        ll e = i*i;
        if(e%2==1){
            if((e-1)/2 + 1 <= 1e9) v.push_back((e-1)/2 + 1);
            else break;
        }
    }
    //cout << v.size() << '\n' ;

    // for(ll i=0;i<10;i++){
    //     cout << v[i] << ' ';
    // }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll l=0-1 , r=v.size()-1+1;
        while(r-1 > l){
            ll mid = (l+r)/2;
            if(v[mid] <= n) l=mid;
            else r=mid;
        }
        cout << l+1 << '\n' ;
        //cout << v[l] << '\n';
    }




    return 0;
}