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
        ll n,k ; cin >> n >> k;
        set<ll> s;
        ll crh =0;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            if(i==k-1) crh = x;
            s.insert(x);
        }
        vector<ll> v;
        for(auto i : s) v.push_back(i);
        ll id=0;
        while(v[id]!=crh){
            id++;
        }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n';
        ll crwl = 1 , fg=0;
        for(ll i=id;i<v.size();i++){
            //cout << i << ' ' << v[i] << ' ' << v[i+1] <<' ' <<crwl << '\n';
            if(i!=v.size()-1 && (v[i] - crwl+1 >= v[i+1]-v[i])){
                crwl += v[i+1]-v[i];
            }
            else if(i!=v.size()-1){
                fg=1; break;
            }
            //cout << crwl << '\n';
        }
        
        if(fg) cout << "NO" << '\n';
        else cout << "YES" << '\n' ;
    }
    
    
    return 0;
}