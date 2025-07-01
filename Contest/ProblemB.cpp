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
    while(t--)
    {
        ll n,j,k; cin >> n >>  j >> k;
        ll mx= lmin;
        vector<ll> v(n);
        for(auto &i: v){
            cin >> i;
            if(i>mx) mx=i;
        }
        
        if(v[j-1]==mx){
            cout << "YES" << '\n';
        }
        else {
            if(k>=2) cout <<"YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    
    

    return 0;
}