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
        set<ll> s; map<ll , ll> mp;
        for(ll i=0;i<n;i++){
            ll x;cin >> x;
            s.insert(x);
            mp[x]++;
        }
        vector<pair<ll , ll>> v;
        for(auto i : s){
            v.push_back({i , mp[i]});
        }
        ll fg=0;
        // for(auto i : v){
        //     cout << i.first << ' ' << i.second << '\n';
        // }
        //cout << v[0].first << '\n';
        for(ll i=0;i<v.size() && fg!=2;i++){
            if(i==0 && (v[i].first != 0 )) {cout << 0 << '\n'; fg=2;}
            else if(i!=0 && v[i].first != v[i-1].first+1) {cout<< v[i-1].first+1 << '\n';fg=2;}
            else if(i!=0 && v[i].second < 2 && fg==1) {cout<<v[i].first <<'\n';fg=2;}
            else if(v[i].second < 2 && fg==0) {fg=1;}
        }

        if(fg==0 || fg==1) cout << v[v.size()-1].first +1 << '\n';

    }


    return 0;
}