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

void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr<< "]\n"; return ;
}
struct Comp{
    bool operator()(const pair<ll,ll> a,const pair<ll,ll> b)const{
        if(a.second!=b.second) return a.second>b.second;
        return a.first<b.first;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k ; cin >> n >> k;

    set<pair<ll,ll> , Comp> s;
    
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++) cin >> v[i];

    map<ll,ll> mp;

    for(ll i=1;i<=k;i++){
        if(mp.find(v[i])!=mp.end()) {
            s.erase({v[i] , mp[v[i]]});
            mp[v[i]]++;
            s.insert({v[i] , mp[v[i]]});
        }
        else {mp[v[i]]=1; s.insert({v[i] , mp[v[i]]});}
    }
    cout << (*(s.begin())).first << ' ';
    for(ll i=k+1;i<=n;i++){
        if(mp.find(v[i]) != mp.end()) {
            s.erase({v[i] , mp[v[i]]});
            mp[v[i]]++;
            s.insert({v[i] , mp[v[i]]});
        }
        else {mp[v[i]]=1;s.insert({v[i] , mp[v[i]]});}


        s.erase({v[i-k] , mp[v[i-k]]});
        mp[v[i-k]]--;
        if(mp[v[i-k]]) s.insert({v[i-k] , mp[v[i-k]]});

        //for(auto j : s) cout << i << ' ' << j .first <<' ' << j.second << '\n' ;


        cout << (*(s.begin())).first << ' ';
    }





    return 0;
}