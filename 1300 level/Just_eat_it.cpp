#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
        ll n; cin >> n;
        vector<ll> v;
        map<ll , ll>  mp;
        set<ll> s;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            if(i==0) v.push_back(x);
            else v.push_back(v[i-1]+x);
        }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n';
        for(ll i=0;i<n-1;i++){
            s.insert(v[i]);
            mp[v[i]] ++; // last element of v[i] will not be pushed
        }
        ll ans=lmin ;
        for(ll i=0;i<n;i++){
            if(i==0){
                ll e=*(--s.end());
                ans = max(ans , e-0);
                s.insert(v[n-1]);
                mp[v[n-1]]++;
            }
            else{
                mp[v[i-1]]--;
                if(mp[v[i-1]]==0) s.erase(v[i-1]);
                ll e=*(--s.end());
                ans = max(ans , e-v[i-1]);
            }
        }
        //cout << ans << '\n';

        if(ans  < v[n-1]) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }




    return 0;
}