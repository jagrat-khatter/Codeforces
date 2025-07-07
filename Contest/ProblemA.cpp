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
ll mod(ll n){
    if(n>0) return n;
    else return -n;
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
        ll n,s; cin >> n >> s;
        vector<ll> v(n);
        ll mx=lmin , mn = lmax;
        for(auto &i : v) {cin >> i;
        mx = max(mx , i);
        mn = min(mn , i);
        }
        if(s<=mn){
            cout << mx-s << '\n';
        }
        else if(s>=mx) cout << mod(mn-s) << '\n';
        else {ll res1 = mod(mx-s);
        ll res2 = mod(mn-s);
        cout << min(res1 , res2) * 2  + max(res1 , res2) << '\n';}


    }
    
    

    return 0;
}