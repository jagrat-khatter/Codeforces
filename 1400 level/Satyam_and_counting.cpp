#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value * value ;
    else return value * value * b;
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
    if(n>0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        set<ll> y0,y1; // we'll store the x-coordinates of points which lie in y=0 and y=1
        map<ll , ll> m0,m1; 
        set<pair<ll,ll>> s;
        ll n; cin >> n;
        for(ll i=0;i<n;i++){
            ll a,b; cin >> a >> b;
            s.insert({a,b});
            if(b==0) y0.insert(a);
            else y1.insert(a);
        }
        ll ans=0 ;
        // first cases triangles where two points exist with same x coordinate in y1 and y0
        for(auto j : y0){
            if(y1.find(j) != y1.end()) {
                ans += y1.size()-1 + y0.size()-1;
            }
        }
        //Case 2 
        for(auto j : y0){
            // for j j-1 and j+1 should exist in y1
            if( (y1.find(j-1)!=y1.end())   &&   (y1.find(j+1)!=y1.end()) ) ans++;
        }
        for(auto j : y1){
            // for j j-1 and j+1 should exist in y0
            if( (y0.find(j-1)!=y0.end())   &&   (y0.find(j+1)!=y0.end()) ) ans++;
        }

        cout << ans << '\n' ;
    }



    return 0;
}