#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
bool comparator(pair<pair<ll,ll> ,ll> a,pair<pair<ll,ll> ,ll> b){
    if(a.first.first != b.first.first) return a.first.first<b.first.first;
    else return a.first.second < b.first.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<pair<ll,ll> ,ll>> v;
        set<ll> rs; map<ll,ll> mp;
        for(ll i=1;i<=n;i++){
            ll a,b; cin >> a >> b;
            v.push_back({{a,b} , i});
            
        }
        sort(v.begin() , v.end() , comparator);
        
        ll ans=-1;
        for(ll i=0;i<n;i++){
            if(rs.size()){
                if(v[i].first.first > *(--rs.end())) {ans=v[i].first.first;break;}
            }

            rs.insert(v[i].first.second);
        }

        if(ans==-1) {cout << - 1<< '\n' ; continue;}

        vector<ll> vans(n+1 ,0);
        for(ll i=0;i<n;i++){
            if(v[i].first.first < ans) vans[v[i].second]=1;
            else vans[v[i].second]=2;
        }
        for(ll i=1;i<=n;i++){
            cout << vans[i] << ' ';
        }
        cout << '\n' ;

    }

    return 0;
}