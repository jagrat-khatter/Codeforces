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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll x,k ; cin >> x >>k;
        if(x==1 && k==1) {cout << "NO" << '\n'; continue;}
        if(x==1){
            ll n=0 , fg=0;
            for(ll i=k;i>=1;i--){
                n += power(10 , i-1);
            }
            //cout << n << '\n';
            for(ll i=2;i*i<=n;i++){
                if(n%i==0) {fg=1; break;}
            }
            if(!fg) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else if(k==1){
            ll fg=0;
            for(ll i=2;i*i<=x;i++){
                if(x%i==0) {fg=1; break;}
            }
            if(!fg) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    
    

    return 0;
}