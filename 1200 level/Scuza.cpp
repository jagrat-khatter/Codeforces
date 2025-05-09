#include <bits/stdc++.h>
using namespace std;
using ll= long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool comparator(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first != b.first) return a.first<b.first;
    else return a.second<b.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,q; cin >> n >> q;
        vector<pair<ll,ll>> v;
         
        vector<ll> s;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back({x , i});
            if(i==0) s.push_back(x);
            else s.push_back(s[i-1] + x);
        }
        sort(v.begin() , v.end() , comparator);
        vector<ll> mn;
        for(ll i=n-1;i>=0;i--){
                if(i==n-1) mn.push_back(v[i].second);
                else {
                    if(v[i].second<mn[n-1-i-1]) mn.push_back(v[i].second);
                    else mn.push_back(mn[n-1-i-1]);
                }
        }
        reverse(mn.begin() , mn.end());
        // for(auto i : mn) cout << i << ' ';
        // cout << '\n';
        for(ll i=0;i<q;i++)
        {
            ll target; cin >> target;
            ll l=0-1 , r = n-1+1;
            while(r-1>l){
                ll mid =(l+r)/2;
                if(v[mid].first <= target) l = mid;
                else r = mid;
            }// In the end r will give element greater than target
            // cout << l << ' ';
            // cout << v[l].second-1 << '\n';
            if(r<0) cout << 0 << ' ';
            else if(r<n && mn[r]!=0) cout << s[mn[r]-1] << ' ';
            else if(r<n && mn[r]==0)  cout << 0 << ' ';
            else if(r==n) cout << s[n-1] << ' ';
        }
        cout << '\n';

    }


    return 0;
}