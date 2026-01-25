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
    for(auto j : v) cout << j << ' ';
    cerr << "]\n"; return ;
}
bool comparator(pair<pair<ll,ll> ,ll> a,pair<pair<ll,ll> ,ll> b){
    if(a.first.first != b.first.first) return a.first.first<b.first.first;
    else return a.first.second>b.first.second;// This condition is very very important
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;cin >> n;
    vector<pair<pair<ll,ll> ,ll>> v;
    for(ll i=0;i<n;i++){
        ll a,b; cin >> a >> b;
        v.push_back({{a,b},i});
    }

    sort(v.begin() , v.end() , comparator);
    
    set<pair<ll,ll>> rs; // will store all the rs from the prefix with its origial id

    //for(auto j : v) cout << j.first.first << ' ' << j.first.second << ' ' << j.second << '\n' ;
    
    ll ans=-1 , ans2=-1;
    for(ll i=0;i<n;i++){
        if(rs.size()){
            pair<ll,ll> mxr = *(--rs.end());
            if(v[i].first.second<=mxr.first) {ans=v[i].second;ans2=mxr.second;break;}
        }

        if(ans==-1){
            rs.insert({v[i].first.second , v[i].second});
        }
    }
    // print i j such that ai lies inside aj
    if(ans!=-1) cout << ans+1 << ' ' << ans2+1 << '\n';// printing original index in 1 based indexing
    else cout << -1 << ' ' << -1<< '\n' ;


    return 0;
}