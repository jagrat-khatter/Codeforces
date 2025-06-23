#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool comparator(pair<ll , ll> a, pair<ll , ll> b){
    if(a.second!=b.second) return a.second <= b.second ;
    else return a.first <= b.first ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,W ; cin >> n >> W;
        ll u = W , d = (W+2-1) / 2;
        vector<pair<ll , ll>> v;
        set<ll> s;
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll x ; cin >> x; sum+=x ; 
            v.push_back({i , x});
        }
        sort(v.begin() ,v.end() , comparator);
        // for(auto i : v) cout << i.first << ' ' << i.second << '\n';
        if(sum < d) cout << -1 << '\n';
        else if(v[0].second > u) cout << -1 << '\n';
        else {
            ll lst = v.size()-1;
            while(sum>W){
                ll l=0-1 , r = lst+1;
                while(r-1 > l){
                    ll mid = (l+r)/2;
                    if(sum - v[mid].second >= d) l=mid;
                    else r=mid;
                }
                if(l<0) break;
                // cout << v[l].second << ' ';
                s.insert(v[l].first);
                sum -= v[l].second;
                lst = l-1;
            }
            // cout << '\n';
            // for(auto i : s) cout << i << ' ';
            // cout << '\n';
            vector<ll> ans ;

            if(sum<=u && sum>=d){
                for(ll i=0;i<n;i++){
                    ll e = v[i].first;
                    if(s.find(e) == s.end()) ans.push_back(e+1);
                }
                cout << ans.size() << '\n';
                for(auto i : ans) cout << i << ' ';
                cout << '\n';
            }
            else cout << -1 << '\n';
        }

    }


    return 0;
}