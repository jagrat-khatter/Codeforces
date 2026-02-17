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
    if(a.second != b.second) return (a.second<b.second);
    else return (a.first<b.first);// this does not matter beacuse in both ending time with be same
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<pair<ll,ll>> inrs; // this will store all the intervals
    // To maximize non overlapping intervals you have to sort intervals based on who finishes first 
    // if we sort this way then and choose intervals then we'll have best possibility of choosing 
    // intervals ahead
    for(ll i=1;i<=n;i++){
        ll a,b; cin >> a >> b;
        inrs.push_back({a , b});   
    }

    sort(inrs.begin() , inrs.end() , comparator);
    ll le = -1; // last ending time 
    ll ans=0;
    for(ll i=0;i<inrs.size();i++){
        //cout << inrs[i].first << ' ' << inrs[i].second << '\n' ;
        if(inrs[i].first>=le){
            le = inrs[i].second;
            ans++;
        }
    }

    cout << ans << '\n' ;


    return 0;
}