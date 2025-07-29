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
        ll w,h,a,b; cin >> w >> h >> a >> b;
        ll x1,y1,x2,y2; cin >> x1>>y1>>x2>>y2;
        if(mod(x1-x2)%a==0  &&   mod(y1-y2)%b==0) cout << "YES" << '\n';
        else if(mod(x1-x2)%a==0 && mod(x1-x2)>=a) cout << "YES" << '\n';
        else if(mod(y1-y2)%b==0 && mod(y1-y2)>=b) cout << "YES" << '\n';
        else cout << "NO" << '\n' ;
    }

    

    return 0;
}