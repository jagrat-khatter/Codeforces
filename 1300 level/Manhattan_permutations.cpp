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
        ll n,k ; cin >> n >> k;
        if(n==1 && k!=0)
        {
            cout << "NO" << '\n'; continue;
        }
        else if(n==1){
            cout << "YES" << '\n';
            cout << 1 << '\n'; continue;
        }
        vector<ll> v;
        ll st = n-1;
        for(ll i=st;i>0;i-=2){
            if(i==st) v.push_back(2*i);
            else v.push_back(v[v.size()-1] + 2* i);
        }
        //cout << v[v.size()-1] << '\n';
        if(v[v.size() - 1] <k || k%2!=0){
            cout << "NO" << '\n'; continue;
        }
        

        ll l =0-1 , r = v.size()-1+1;
        while(r-1 > l)
        {
            ll mid = (l+r) / 2;
            if(v[mid] <= k) l = mid;
            else r = mid;
        }
        //cout << l << '\n';
        vector<ll> s;
            for(ll i=1;i<=l+1;i++){
                s.push_back(i) ; s.push_back(n-i+1);
            }
        if(k!=0 && v[l] != k){
            ll diff ;
            if(l!=-1) diff =(k - v[l]) / 2;
            else diff = k / 2;
            s.push_back(l+1+1);
            s.push_back(l+1+1+diff);
        }
        sort(s.begin() , s.end());
        // for(auto i : s) cout << i << ' ';
        // cout << '\n';

        map<ll , ll> mp;
        for(ll i=0;i<s.size();i++){
            mp[s[i]] = s[s.size()-1-i];
        }
        cout << "YES" << '\n';
        for(ll i=1;i<=n;i++){
            if(mp[i]) cout << mp[i] << ' ';
            else cout << i << ' ';
        }
        cout << '\n';
        
        
    }
    return 0;
}