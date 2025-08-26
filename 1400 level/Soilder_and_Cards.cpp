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
ll fact(ll n){
    if(n==0) return 1;
    else return fact(n-1)*n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        ll sa , sb; deque<ll> a,b;
        
        cin >> sa;
        for(ll i=0;i<sa;i++){
            ll x; cin >> x;
            a.push_back(x);
        }
        cin >> sb;
        for(ll i=0;i<sb;i++){
            ll x; cin >> x;
            b.push_back(x);
        }
        bool ans= false;ll mc = fact(n+1);
        for(ll ct=1;ct<=mc;ct++){
            if(a.empty() || b.empty()){
                cout << ct-1 << ' '; 
                if(a.empty()) cout << 2 << '\n';
                else cout << 1 << '\n'; 
                ans = true;
                break;
            }
            ll p = a[0] , q = b[0];
            if(p > q){
                a.pop_front();
                b.pop_front();
                a.push_back(q); a.push_back(p);
            }
            else {
                a.pop_front();
                b.pop_front();
                b.push_back(p); b.push_back(q);
            }
            
        }
        if(!ans) cout << -1 << '\n'; 
        
    }




    return 0;
}