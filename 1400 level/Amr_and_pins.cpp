#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
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
ll cil(long double n){
    ll nf = (ll)(n);
    if(n-nf==0) return nf;
    else return nf+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        long double r , x1,y1,x2,y2 ; cin >> r >> x1 >> y1 >> x2 >> y2;
        long double dist = sqrt((x1-x2)*(x1-x2)  + (y1-y2)*(y1-y2)) ;
        
        cout << cil(dist / (2*r)) << '\n';
    }


    return 0;
}