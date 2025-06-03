#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<pair<ll ,ll>> v;
        for(ll i=0;i<n;i++){
            ll a,b; a=i+1;cin >> b;
            if(a>b) v.push_back({a , b});
        }
        vector<ll> f;
        for(auto i : v)
        {
            if(v[0].first < i.second) f.push_back(i.second);
        }
        sort(f.begin() , f.end());
        // for(auto i : f) cout << i <<  ' ';
        // cout << '\n';
        
        ll l=0-1 , r=f.size()-1+1;
        ll ans=0;
        for(ll i=0;i<v.size();i++){
            ll target = v[i].first;
            r=f.size()-1+1;
            while(r-1>l){
                ll mid = (l+r)/2;
                if(f[mid]<=target) l=mid; // true condintion
                else r=mid;  // false condition
            }

            ans += f.size() - r;
        }

        cout << ans << '\n';
    }




    return 0;
}