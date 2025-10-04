#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vector<ll> v(n);
        for(auto & i : v) cin >> i;
        vector<ll> xr,on,inf;

        if(v[0]==1) {xr.push_back(0);on.push_back(1);}
        else {xr.push_back(1); on.push_back(0);}

        inf.push_back(0);

        for(ll i=1;i<n;i++){
            if(v[i]==1) {xr.push_back(xr[xr.size()-1] + 0); on.push_back(on[on.size()-1]+1);}
            else {xr.push_back(xr[xr.size()-1] + 1); on.push_back(on[on.size()-1]+0);}

            // if not inflection (element is same as of previous element)
            if(v[i]==v[i-1]) inf.push_back(inf[inf.size()-1] + 1);
            else inf.push_back(inf[inf.size()-1] + 0);
        }
        // for(auto j : xr) cout << j << ' ';
        // cout << '\n';
        // for(auto j : on) cout << j << ' ';
        // cout << '\n';
        // for(auto j : inf) cout << j << ' ';
        // cout << '\n';

        
        while(q--){
            ll l,r; cin >> l>> r;
            l--; r--;// making it zero based indexing
            ll n0 , n1 , ni ;
            if(l!=0){
                n0 = xr[r] - xr[l-1];
                n1 = on[r] - on[l-1];
                ni = inf[r] - inf[l];
            }
            else {
                n0 = xr[r];
                n1 = on[r] ;
                ni = inf[r] ;
            }
            if(n0%3 ==0 && n1%3 ==0){
                ll ct=(n0 + n1)/3;
                if(ni>0) cout << ct << '\n';
                else cout << ct+ 1 << '\n';
            }
            else cout << -1 << '\n';
        }
    }




    return 0;
}