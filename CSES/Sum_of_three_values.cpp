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

    ll n,x ; cin >> n >> x;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i].first ; v[i].second = i+1;
    }

    sort(v.begin() , v.end());
    for(ll i=0;i<n;i++){
        ll k = n-1;
        for(ll j=i+1;j<n;j++){
            ll rem = x - v[i].first - v[j].first;
            
            while(k>j && v[k].first>rem) k--;
            if(k==j) break;

            if(v[k].first==rem) {cout << v[i].second << ' ' << v[j].second << ' ' <<v[k].second << '\n'; return 0;}
        }
    }

    cout << "IMPOSSIBLE" ;

    return 0;

    
}