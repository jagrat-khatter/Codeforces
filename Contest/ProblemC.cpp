#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n);   for(auto &i : v) cin >> i;
        ll ans=lmax;
        for(ll i=0;i<n;i++){
            // now we'll look for chunks of same element
            ll j=i;
            while(v[j]==v[i] && j<n) j++;
            j--;
            //cout <<i << ' ' <<j << '\n';
            ans = min(ans , (i-0 + n-1-j)*v[i]);
            i=j;
        }


        cout << ans << '\n' ;
    }

    

    return 0;
}