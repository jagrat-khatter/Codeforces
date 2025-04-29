#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , sum=0; cin >> n;
        vector<ll> v , m;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        m = v;
        sort(v.begin() , v.end());
        vector<ll> ps;
        for(ll i=0;i<n;i++)
        {
            sum +=  v[i];
            ps.push_back(sum);
        }
        vector<ll> ans; ll id=n-1;
        for(ll i=n-1;i>=0;i--)
        {
            if(i==n-1) ans.push_back(n-1);
            else{
                if(ps[i]<v[i+1]) id = i;

                ans.push_back(i + id - i) ;
            }
        }
        reverse(ans.begin() , ans.end()) ;
        // for(ll i=0;i<n;i++) cout << ans[i] << ' ';
        
        // cout << '\n' ;
        

        for(ll i=0;i<n;i++)
        {
            ll target = m[i]; // will search index in vector v // ten access answer corresponding to that
            ll l= 0-1 , r = (n-1)+1;
            while(r-1>l)
            {
                ll mi = (l+r)/2;
                if(v[mi] <=target) l=mi;
                else r = mi;
            }

            cout << ans[l] << ' ';      // l is the last index of target(if multiple)
        }
        cout << '\n' ;
    }


    return 0;
}