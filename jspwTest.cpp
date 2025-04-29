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
    while(t--){
        string s; cin >> s;
        map<ll , ll> mp;

        ll n = s.size();
        for(ll i=0;i<n;i++){
            char e = s[i];// convert  e to number
            ll en = (int)e - 48;
            mp[en]++;
        }
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll lm = 9-i;
            
            while(1)
            {
                if(mp[lm]>=1) {v.push_back(lm); mp[lm]-- ; break;}
                else lm++;
            }
        }
        for(ll i=0;i<n;i++){
            cout << v[i];
        }
        cout << '\n' ;

    }


    return 0;
}