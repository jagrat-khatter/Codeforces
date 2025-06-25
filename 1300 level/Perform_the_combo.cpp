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
        ll n,m; cin >> n >> m;
        string s; cin >> s;
        vector<ll> v(m);
        for(auto & i : v) cin >> i;

        sort(v.begin() , v.end());
        map<char , ll> mp;
        for(ll i=0;i<n;i++){
            char e = s[i];
            ll target = i+1;
            ll l=0-1 , r=m-1+1;
            while(r-1>l){
                ll mid = (l+r)/2;
                if(v[mid]<target) l = mid;
                else r = mid;
            }
            mp[e] += m - r +1 ;
        }
        for(ll i=97;i<=122;i++)
        {
            char e = (char)(i);
            cout << mp[e] << ' ';
        }
        cout << '\n';
        
    }


    return 0;
}