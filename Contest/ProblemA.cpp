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
        ll k,a,b,x,y;
        cin >> k >>a >> b>>x>>y;
        if(x>y){
            ll ansy=0;
            if(k >= b) ansy = (k - b + 1 + y - 1) / y ;
            ll rem = k - ansy * y;
            //cout << ansy << ' ' << rem << '\n';
            ll ansx=0;
            if(rem >= a) ansx= (rem - a + 1 + x -1 ) / x;
            cout <<ansx + ansy << '\n' ;
        }
        else {
            ll ansx=0;
            if(k>=a)  ansx = (k - a + 1 + x -1 ) / x ;
            ll rem = k - ansx * x;
            ll ansy=0;
            if(rem >= b) ansy= (rem - b + 1 + y-1) / y;
            cout <<ansx + ansy << '\n' ;
        }
    }

    

    return 0;
}