#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        if(n==1) {
            cout << 0 << '\n' ; continue;
        }
        vector<ll> s1,s2;
        s1.push_back(v[0]);
        for(ll i=1;i<n;i++)
        {
            s1.push_back(s1[i-1] + v[i]);
        }
        s2.push_back(v[n-1]);
        for(ll i=n-1-1;i>=0;i--)
        {
            s2.push_back(s2[n-i-2] + v[i]);
        }
        ll ans = 0 ;
        for(ll i=0;i<n;i++)
        {
            s2.pop_back();
            // now we'll search if s1[i] exist in remaining vector or not
            ll l=0-1 , r=s2.size()-1+1;
            ll target = s1[i] ; 
            while(r-1>l)
            {
                ll mid=(l+r)/2;
                if(s2[mid]<=target) l=mid;
                else r=mid;
            }
            if(l>=0 && s2[l]==target) {ans = max(ans , (i+1)+(l+1)) ; 
                //cout << target << ' ' << l << '\n';
            }
        }
        cout << ans << '\n' ;
    }




    return  0;
}