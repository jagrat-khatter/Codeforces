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

    return gcd(a , b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll ,ll> mp;
        set<ll> s;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x; s.insert(x);mp[x]++;
        }
        for(auto i : s){
            for(ll j=2;j<=mp[i];j+=2){
                v.push_back(i);
            }
        }
        vector<ll> ans(8);
        // ans vector 
        // 0  1  2  3  4  5  6  7
        // x1 y1 x2 y2 x3 y3 x4 y4
        if(v.size() >= 4){
            ll p = v[0];
            ll q = v[1];
            ll r = v[v.size()-2];
            ll s = v[v.size()-1];
            ans[0]=p ; ans[2]=p;
            ans[1]=q; ans[5]=q;
            ans[4]=r; ans[6]=r;
            ans[3]=s; ans[7]=s;
            cout << "YES" << '\n' ;
            for(auto j : ans) cout << j << ' ';

            cout << '\n' ;
        }
        else{
            cout << "NO" << '\n' ;
        }
        
    }



    return 0;
}