#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll order(ll a, ll b){
    if(a>b) return 1;
    else return -1;
}
bool isPresent(ll n, set<ll> &s){
    if(s.find(n) != s.end()) return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(n);
    ll ans=0;
    for(auto &i : v) cin >> i;
    ll pr=1;
    set<ll> s;
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        if(x == v[pr-1]){
            pr++;
        }
        else{
            s.insert(x);
            ans++;
        }

        while(isPresent(v[pr-1] , s)){
            s.erase(v[pr-1]);
            pr++;
        }
    }
    

    cout << ans << '\n';


    return 0;
}