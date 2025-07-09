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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll a,b,x,y; cin >> a >> b >> x >> y;
        if(b>=a){
            ll cst =0 ;
            for(ll i=a;i<b;i++){
                if(i%2!=0)  cst += x;
                else cst += min(x,y);
            }
            cout << cst << '\n';
        }else{
            if(a-b==1 && a%2!=0) cout << y << '\n';
            else cout << -1 << '\n';
        }
    }
    

    return 0;
}