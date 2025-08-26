#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    ll n,m  ; cin >> n >> m;
    ll g[n+1][m+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> g[i][j];
        }
    }
    ll q; cin >> q;
    while(q--){
        ll sum =0 ;
        ll a,b,c,d; cin >> a >> b >> c >> d;
        for(ll i=a;i<=c;i++){
            for(ll j=b;j<=d;j++){
                sum += g[i][j];
            }
        }

        cout << sum << '\n';
    }
    

    return 0;
} 