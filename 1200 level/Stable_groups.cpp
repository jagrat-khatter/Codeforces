#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,k,x; cin >> n >> k >> x;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll p ; cin >> p;
            v.push_back(p);
        }
        sort(v.begin() , v.end());
        vector<ll> df;
        for(ll i=1;i<n;i++){
            if(v[i] - v[i-1] > x) df.push_back(v[i] - v[i-1]);
        }
        sort(df.begin() , df.end());
        // for(auto i : df) cout << i << ' ';
        // cout << '\n';
        ll ans = df.size()+1;
        for(ll i=0;i<df.size();i++){
            if((df[i] +x -1)/ x  -1  <= k){
                // cout << (df[i] +x -1)/ x  -1  << ' ' << k << '\n';
                ans--;
                k -= (df[i] +x -1)/ x  -1;
            }
            else break;
        }
        cout << ans << '\n';
    }



    return 0;
}