#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MIN;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        set<ll> s; map<ll ,ll> mp;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            mp[x]++;
            s.insert(x);
        }
        ll ans =0;
        while(s.size())
        {
            ll lst = -1;
            ans++;
            vector<ll> v;
            for(auto i : s){
                
                if(lst==-1 || i==lst+1) {
                    mp[i]--;
                    lst = i;
                    if(mp[i]==0) v.push_back(i);
                }
                else break;
            }
            for(auto i : v) { // all the elemeents whose frequency has turned to sero
                s.erase(i);
            }
            
        }
        cout << ans << '\n';
    }


    return 0;
}