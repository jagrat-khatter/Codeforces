#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n;cin >> n;
        vector<vector<ll>> v(n+1); // for all the elements we'll store at which index they are appearing
        for(ll i=1;i<=n;i++){ 
            ll x; cin >> x; v[x].push_back(i);
        }

        vector<set<ll>> ds(n+1);
        for(ll i=1;i<=n;i++){
            ll mx = imin;
            for(ll j=1;j<v[i].size();j++){
                mx = max(mx , v[i][j] - v[i][j-1]);
            }
            ll sz = v[i].size();

            
            // we also need to look the starting,ending id of element not just distance in middle
            ll id=imin;
            if(sz>=1) id = max({v[i][0] , n-v[i][sz-1]+1 , mx});
            if(id!=imin) {//cout << i << ' ' << id << '\n' ;
            ds[id].insert(i);}
        }

        ll ans=-1;
        for(ll i=1;i<=n;i++){
            if(ds[i].size()){
                if(ans==-1) ans= *(ds[i].begin());
                else ans = min(ans , *(ds[i].begin()));
            }
            cout << ans << ' ' ;
        }

        cout << '\n' ;

    }




    return 0;
}