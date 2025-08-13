#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
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

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        ll ans=0;
        ll fg=0;
        vector<ll> v(n); for(auto &j : v) cin >> j;
        for(ll i=1;i<n;i++){
            ll a = min(v[i-1] , v[i]);
            ll b = max(v[i-1] , v[i]);
            if(a==1 && b==2) ans+= 3;
            else if(a==1 && b==3) ans+=4;
            else {fg=1; break;}
        }
        ll ct=0;
        for(ll i=0;i<=n-3;i++){
            if(v[i]==3 && v[i+1]==1 && v[i+2]==2) ct++;
        }
        if(!fg) {
            cout << "Finite" << '\n';
            cout << ans - ct << '\n';
        }
        else cout << "Infinite" << '\n' ;
    }


    return 0;
}