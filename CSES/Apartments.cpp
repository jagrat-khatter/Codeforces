#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
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
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr<< "]\n"; return ;
}
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second!=b.second) return (a.second<b.second);
    else return (a.first < b.first);
} 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k; cin >> n >> m >> k;
    vector<pair<ll,ll>> v;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x;
        v.push_back({x-k , x+k});
    } 
    sort(v.begin() , v.end() , comparator);
    vector<ll> b;
    for(ll i=1;i<=m;i++){
        ll x; cin >> x; b.push_back(x);
    }
    sort(b.begin() , b.end());
    //for(auto j : v) cout << j.first << ' ' << j.second << '\n' ;
    ll ptr=0;
    ll ans=0;
    for(ll i=0;i<v.size();i++){
        if(b[ptr]<v[i].first){
            while(ptr<b.size() && b[ptr]<v[i].first){
                ptr++;
            }
            if(ptr<b.size() && b[ptr]>=v[i].first && b[ptr]<=v[i].second) {ans++; ptr++;}
        }
        else if(ptr<b.size() && b[ptr]>=v[i].first && b[ptr]<=v[i].second) {ans++; ptr++;}
    }

    cout << ans <<'\n' ;

    return 0;
}