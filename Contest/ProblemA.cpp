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
    
    set<ll> s; // squares
    for(ll i=1;i<=10000;i++){
        s.insert(i*i);
        if(i*i > 300000){
            break;
        }
    }

    ll t; cin >> t;
    while(t--)
    {
        ll l1,b1,l2,b2,l3,b3; cin >> l1>> b1>>l2>>b2>>l3>>b3;
        if(b1==b2 && b2==b3 && l1+l2+l3==b1) cout << "YES" << '\n';
        else if(l1==l2 && l2==l3 && b1+b2+b3==l1) cout << "YES" << '\n';
        else if(l2==l3 && b1==b2+b3 && l1+l2==b1) cout << "YES" << '\n';
        else if(l1==l2+l3 && b3==b2 && l1==b1+b3) cout << "YES" << '\n';
        else cout << "NO" << '\n' ;
        
        
    }
    

    return 0;
}