#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    


    ll t; cin >> t;
    while(t--){
        ll n;cin >> n;
        ll i,j,k; i=1;j=2;k=3;
        while(1){
            cout << "? " << i << ' ' << j << ' ' << k << '\n';
            ll id ; cin >> id;
            if(id == 0) {cout <<"!"<< ' ' << i << ' ' << j << ' ' << k << '\n'; break;}
            long double a = (long double)(rand()) / RAND_MAX;
            if(a<=0.3333333) i=id;
            else if(a<=0.666666666) j=id;
            else k=id;
        }
    }
    
    
    return 0;
}