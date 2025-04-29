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
        ll n ; cin >> n;
        ll ans=0 ;
        set<ll> s;
        map<ll ,ll> mp;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            if(x!=0){
                s.insert(x);
                mp[x]++;
            }
            else{
                if(s.size()==0){continue;}
                ll e = *(--s.end()) ; // dereferncing the maximum element of the set
                ans += e;
                mp[e]--;
                if(mp[e]==0) s.erase(e); // if the frequency of maximum element was one then we'll erase that from set
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
