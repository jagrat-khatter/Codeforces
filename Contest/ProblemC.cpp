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

    else return (b , b%a);
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
bool comparator(pair<ll,ll> a , pair<ll,ll> b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second< b.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        vector<ll> a(n),b(n);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        vector<pair<ll,ll>> v;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(a[i] > b[i]){
                v.push_back({b[i] , a[i]});
            }
            else v.push_back({a[i] , b[i]});
            ans += mod(a[i] - b[i]);
        }
        sort(v.begin() , v.end() , comparator);
        ll ct=lmax;

        // for(auto j : v){
        //     cout << j.first << ' ' << j.second << '\n';
        // }
        
        for(ll i=0;i<v.size()-1;i++){
            pair<ll,ll> p=v[i];
            pair<ll,ll> q=v[i+1];
            ll pc = mod(p.first - p.second) + mod(q.first - q.second);
            vector<ll> tm;
            tm.push_back(p.first); tm.push_back(q.first); tm.push_back(p.second); tm.push_back(q.second); 
            sort(tm.begin() , tm.end());
            // for(auto )
            ll pc2 = mod(tm[2]-tm[0]) + mod(tm[3]-tm[1]);
            ll delta = mod(pc2 - pc);
            ct = min(ct , delta);
        }
        //cout << ct << '\n' ;
        cout << ans + ct << '\n';

    }

    

    return 0;
}