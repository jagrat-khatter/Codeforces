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

    return gcd(b , a%b);
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
ll powerOF10(ll n){
    ll ct = 0;
    while(n%10==0){
        ct++; n=n/10;
    }
    return ct;
}
ll good(ll n){
    if(n>0) return n;
    else return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        // first we'll calculate power of 2 and 5
        ll c2 =0 , c5 =0;
        ll cp=n;
        while(cp%2==0){
            c2++;
            cp = cp/2;
        }
        while(cp%5==0){
            c5++;
            cp = cp/5;
        }
        set<ll> s;
        ll max0 = 0;
        for(ll i=0;i<31;i++){
            for(ll j=0;j<31;j++){
                ll vl = power(2 , i) * power(5 , j) * n ;
                if(vl > 1e18) break;
                if(vl  <=  n*m){
                    s.insert(vl);
                    max0 = max(max0 , powerOF10(vl));
                }
                }
                
        }
        //cout << max0 << ' ' << good(max0-c2) << ' ' << good(max0-c5) << '\n' ;
        // how many tens n can supply 
        ll tens = min(c2 ,c5);
        // max0 - c2  2's and max0-c5  5's k has to supply 
        ll mul = m  / ( power(2 , good(max0-c2)) * power(5  , good(max0-c5)) );
        
        cout << ( power(2 , good(max0-c2)) * power(5  , good(max0-c5)) ) * mul*n << '\n' ;



    }



    return 0;
}