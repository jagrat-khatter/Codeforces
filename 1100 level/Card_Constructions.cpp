#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
const ll lmin = LLONG_MIN;
const ll lamx = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> v;
    for(ll i=1;i<100000;i++)
    {
        ll e= 2*i + ((i-1)*(i)*3)/2;
        if(e>1e9) break;
        
        v.push_back(e);
    }
    
    ll t; cin >> t;
    while(t--)
    {
        ll n  , ct=0; cin >> n;
        while(n>0)
        {
            
            ll l=0-1 , r=v.size()-1+1;
            while(r-1>l)
            {
                ll mid = (l+r)/2;
                if(v[mid] <= n) l =mid;
                else r = mid;
            }
            if(l==-1) break;
            else n = n-v[l];
            ct++;
        }

        cout << ct << '\n' ;
    }
    

    return 0;
}