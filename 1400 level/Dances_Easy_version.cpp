#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return (a , a%b) ;
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
        ll n,m; cin >> n>>m;
        
        vector<ll> a,b;
        a.push_back(1);
        for(ll i=1;i<n;i++){
            ll x; cin >> x;
            a.push_back(x);
        }
        for(ll i=0;i<n;i++){
            ll x;cin >> x;
            b.push_back(x);
        }
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        ll l=0-1 , r=n+1;
        while(r-1 > l){
            ll mid= (l+r)/2;
            if(mid >= n) r=mid;
            else {
                vector<ll> ca,cb;
                for(ll i=0;i<n-mid;i++){
                    ca.push_back(a[i]);
                }
                for(ll i=mid;i<n;i++){
                    cb.push_back(b[i]);
                }
                bool fg=false;
                for(ll i=0;i<ca.size();i++){
                    if(ca[i] >= cb[i]) {fg=true; break;}
                }
                if(!fg) r=mid;
                else l=mid;
            } 
        }

        cout << r << '\n' ;
    }



    return 0;
}