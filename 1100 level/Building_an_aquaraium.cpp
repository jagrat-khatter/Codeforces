#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , x;
        cin >> n >> x;

        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin() , v.end()); 
        vector<ll> p;
        p.push_back(v[0]);
        for(ll i=1;i<n;i++)
        {
            p.push_back(v[i] + p[i-1]);
        }
        ll lmax = v[v.size() - 1];
        ll lmin = v[0];
        // we'll do binary search such that if volume is <= x then predicate function will resukt in true else it will give false
        ll l=0-1 , r= v.size()-1+1;
        while(r-1>l)
        {
            ll mid = (l+r)/2;
            if(v[mid]*(mid+1)-p[mid]  <= x) l = mid;
            else r = mid; 
        }
        
        if(l==v.size()-1)
        {
            // what we have , how much vol. will increase with each increase in height = v.size()
            ll ans = (x - (v[v.size()-1] * v.size()  - p[v.size()-1])) / (v.size()) ;
            //cout << ans << '\n';
            cout << ans + v[v.size()-1] << '\n'; // net height
        }
        else{
            cout << (x-((l+1)*v[l]-p[l])) / (l+1) + v[l]  << '\n';
        }
    }


    return 0;
}