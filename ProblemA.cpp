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
        string s; cin >> s;
        ll ct=0 , ans=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='1') ct++;
        }
        for(ll i=0;i<s.size();i++){
            if(s[i]=='1') ans += (ct-1);
            else ans += (ct+1);
        }

        cout << ans << '\n';
    }



    return 0;
}