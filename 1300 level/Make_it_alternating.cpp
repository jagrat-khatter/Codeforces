#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ;cin >> t;
    while(t--){
        string s , s2; cin >> s;
        ll n = s.size();
        s2.push_back(s[0]);
        for(ll i=1;i<n;i++)
        {
            if(s[i] != s[i-1]){
                s2.push_back(s[i]);
            }
        }
        ll l=0;
        ll i=0;
        vector<ll> v; ll ans=1;
        ll removal =0;
        while(i<s2.size()){
            ll ct=0;
            while(l<n && s[l] == s2[i]){
                ct++;l++;
            }
            if(ct-1>0) {v.push_back(ct);}
            i++;
        }
        for(auto i : v)
        {
            ans = (ans * (i%MOD)) % MOD;
            removal += i-1;
        }
        while(removal){
            ans = (ans * (removal % MOD)) % MOD;
            removal --;
        }
        
        cout << s.size() - s2.size() <<  ' ' << ans << '\n';
        
    }




    return 0;
}