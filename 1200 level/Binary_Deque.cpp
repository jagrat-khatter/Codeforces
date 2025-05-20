#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,s ,as=0; cin >> n >> s; // as is the actual sum that is in full array 
        vector<ll> v;
        map<ll ,ll> mp;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
            as += x;
        }
        mp[0] = -1;
        mp[as+1] = n;
        ll ct=0;
        for(ll i=0;i<n;i++){
            // check for test case when size of array is only one
            ct += v[i];
            if(v[i]==1) mp[ct] = i; 
        }
        //cout <<mp[0] << ' '<< mp[1] << ' '<< mp[2] << ' ' << mp[3] << ' ' << mp[4] << ' ' << mp[5] << ' ' << mp[6] <<' ' << mp[7] << '\n';
        if(s>as) cout << -1 << '\n';
        else {
            ll l =as-s+1 , r = as;
            ll ans= lmin;
            ll g1,g2;
            
            while(l>0){
                if(l>0) g1=mp[l-1] +1;
                else g1 = mp[l];
                if(r<=as) g2=mp[r+1]-1;
                else g2=mp[r];
                ans = max (ans ,(g2 - g1+1)); 
                //cout <<  g2-g1 +1 << '\n';
                // else ans = max (ans ,(mp[r] - mp[l-1] +1)); 
                // we want this mp[r] - mp[l] to maximize so we take mp[l-1] +1 if l>0 
                l--; r--;
            }
            cout << n-ans << '\n' ;
        }
    }



    return 0;
}