#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;t=1;
    while(t--)
    {
        string s; cin >> s;
        vector<pair<char , ll>> v;
        ll n= s.size();
        char ch=s[0];
        ll ct=1;
        vector<ll> f;
        for(ll i=1;i<=n;i++){
            if(i==n || s[i]!=s[i-1]) {
                v.push_back({s[i-1] , ct});
                ct=1;
            }
            else{
                ct++;
            }
        }
        ll p1=0,p2=0;
        for(auto i : v){
            if(i.first == 'v' && i.second >= 2) {f.push_back(i.second);
            p2+= (i.second-1);
        }}

        if(f.size()>=2){
            ll ans=0;
            
            for(ll i=0;i<n && p2!=0;i++){
                if(v[i].first=='v' && v[i].second >=2){
                    p2 -= (v[i].second-1);
                    p1 += (v[i].second-1);
                }
                
                if(v[i].first=='o' && p1!=0 && p2!=0){
                    ans += v[i].second * p1 * p2 ;
                }

            }

            cout << ans << '\n';
        }
        else{
            cout << 0 << '\n';
        }

    }



    return 0;
}
