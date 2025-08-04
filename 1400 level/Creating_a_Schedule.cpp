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
ll floorDist(ll a,ll b){
    a = a/100; b= b/100;
    return mod(a-b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> v(m); for(auto &i : v) cin >> i; sort(v.begin() , v.end());
        vector<ll> odd , even;
        for(ll i=0;i<n;i++){
            odd.push_back(v[i]); // odd period
            even.push_back(v[m-i-1]); // even period
        }
        // for(auto j : v) cout << j << ' ';
        // cout << '\n' ;
        ll ans=0;

        ll p1 = 0 , p2 = v.size()-1;
        
        for(ll j=0;j<n;j++){
            for(ll j=1;j<=6;j++){
                if(j%2==0) cout << v[p1] << ' ';
                else cout << v[p2] << ' ';
            } 
            cout << '\n';
            j++;if(j>=n) break;
            for(ll j=1;j<=6;j++){
                if(j%2==0) cout << v[p2]<< ' ';
                else cout << v[p1] << ' ';
            } 
            p1++;p2--;
            
            cout << '\n' ;
        }

    
    }




    return 0;
}