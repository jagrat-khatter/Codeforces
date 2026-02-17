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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, n; cin >> x >> n;
    set<ll> pts={0 , x}; // all the pts that have traffic light 
    map<ll,ll> ans; // value of path distance where there is no traffic light in between 
    ans[x]=1;
    for(ll i=1;i<=n;i++){
        ll e; cin >> e;
        auto it1 = pts.upper_bound(e);// value strictly greater than it
        auto it2 = pts.lower_bound(e);// assuming this value is not present in set already
        ll e1 , e2;
        // it1 will never be equal to pts.end()
        // --it2 will never be equal to pts.begin()
        // 0 and n are already in the set and e cannot equal to 0 and n
        e1 = *(it1);
        e2 = *(--it2);
        //cout << i << ' ' << e1 << ' ' << e2 << '\n' ;
        pts.insert(e);
        ans[e1-e2]--;
        if(ans[e1-e2]==0) ans.erase(e1-e2);
        ans[e1-e]++; ans[e-e2]++;
        cout << (--(ans.end()))->first << ' ' ;
    }
    

    return 0;
}