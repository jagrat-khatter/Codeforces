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
        if(n<5) cout << -1 << '\n';
        else {
            for(ll i=1;i<=n;i++){
                if(i%2!=0 && i!=5) cout << i << ' '; 
            }
            cout << 5 << ' ';
            cout << 4 << ' ';
            for(ll i=1;i<=n;i++){
                if(i%2==0 && i!=4) cout << i << ' '; 
            }
            cout << '\n' ;
        }
    }

    

    return 0;
}