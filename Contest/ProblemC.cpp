#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        if(n*(n+1) /2 < m || m<n) {cout << -1 << '\n'; continue;}
        vector<ll> v;
        for(ll i=1;i<=n;i++)
        {
            if(i==1) v.push_back(n-i+1);
            else v.push_back(v[v.size()-1] + n-i+1);
        }
        ll l=0-1 , r=v.size()-1+1;
        while(r-1 > l)
        {
            ll mid = (l+r) /2;
            if(v[mid] <= m) l = mid;
            else r = mid;
        }
        // for(auto i : v) cout << i <<  ' ';
        // cout << '\n';
        // index l tak 0 se reverse counting
        vector<ll> final;
        for(ll j=n;j>=n-l+1;j--){
            final.push_back(j);
        }
        if(v[l] == m){
            ll j=1;
            while(1 && final.size()!=n){
                final.push_back(j);
                j++;
            }
        }
        else{
            ll diff = m - v[l] + 1;
            final.push_back(diff);
            ll j=1;
            while(1 && final.size()!=n){
                if(j!=diff) final.push_back(j);
                j++;
            }
        }
        cout << final[0] << '\n';
        for(ll i=0;i<final.size();i++){
            if(i!=0) cout << final[i] << ' ' << final[i-1] << '\n';
        }
    }
    

    return 0;
}