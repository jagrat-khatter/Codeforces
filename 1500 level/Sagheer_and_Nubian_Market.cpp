#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,s; cin >> n >> s;
    vector<ll> v(n); for(auto &i : v) cin >> i;
    vector<ll> pf; pf.push_back(0); // we'll make prefix sum as one based indexing
    for(ll i=1;i<=n;i++){
        pf.push_back(pf[i-1] + v[i-1]);
    }

    ll l=0-1 , r=n+1;// we can minimum 0 souveniers and maximum n
    ll cst =0;
    while(r-1  > l){
        ll m  = (l+r)/2;
        vector<ll> nv;
        for(ll i=0;i<n;i++){
            nv.push_back(v[i] + (m * (i+1)));
        }
        sort(nv.begin() , nv.end());
        cst =0;
        for(ll i=0;i<m;i++){
            cst += nv[i]; // cheapest ways of buying m items
        }
        if(cst<=s) l=m;
        else r=m;
    }
    vector<ll> nv;
    for(ll i=0;i<n;i++){
        nv.push_back(v[i] + (l * (i+1)));
    }
    sort(nv.begin() , nv.end());
    cst =0;
    for(ll i=0;i<l;i++){
        cst += nv[i]; // cheapest ways of buying m items
    }
    cout << l << ' ' << cst << '\n' ;


    return 0;
}