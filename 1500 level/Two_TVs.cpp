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
bool comparator(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i=1;i<=n;i++) {
        ll a,b; cin >> a >> b; v.push_back({a,b});
    }

    sort(v.begin() , v.end() , comparator);

    ll ans=1;
    set<ll> rs;map<ll,ll> mp;
    for(ll i=0;i<n;i++){

        //cout << v[i].first << ' ' << v[i].second << '\n' ;
        if(rs.size()){
            ll overlap = 1;
            if(*(--rs.end()) >= v[i].first) overlap+= mp[*(--rs.end())];
            if(rs.size()>=2 && *(--(--rs.end())) >= v[i].first) overlap+= mp[*(--(--rs.end()))];
            // if first maximum and second maximum contribute in overlap
            if(i+1<n && v[i+1].first==v[i].first) overlap++;
            if(i+2<n && v[i+2].first==v[i].first) overlap++;

            //cout << i << ' ' << overlap << '\n' ;
            if(overlap > 2) {ans=-1; break;  }
            
        }

        rs.insert(v[i].second); mp[v[i].second]++;
    }

    if(ans==-1) cout << "NO\n";
    else cout << "YES\n" ;




    return 0;
}