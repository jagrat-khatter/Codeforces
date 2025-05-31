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
        ll n,x,y; cin >> n >> x >> y;
        vector<pair<ll , ll>> v;
        for(ll i=0;i<n;i++){
            ll p; cin >> p;
            
            v.push_back({p%y , p});
        }
        sort(v.begin() , v.end()); // sorting on the basis of element % y
        vector<ll> a;
        ll ans=0;
        for(ll i=0;i<=n;i++){
            //cout << v[i].first << '\n';
            if(i==n || (i!=0 && v[i].first!=v[i-1].first)){
                //cout << v[i].first << ' ' << 'p'<<' '  << a.size()<< '\n';
                map<ll ,ll> mp;
                ll ct=0;
                for(auto j : a){
                    mp[j]++;
                }
                for(auto j: a){
                    if(mp[x-j] && x-j!=x && x-j!=j){
                        ct += mp[x-j];
                    }else if(x-j==x && mp[0]){
                        ct+= mp[0]-1;
                    }
                    else if(x-j==j && mp[j]){
                        ct+= mp[j]-1;
                    }
                    
                }
                ans += ct/2;
                while(a.size()!=0){
                    a.pop_back();
                }
                if(i!= n) a.push_back((v[i].second)%x);
            }
            else{
                //cout << v[i].first << ' ' << 'q'<< '\n';

                a.push_back((v[i].second)%x);
            }
        }

        cout << ans << '\n' ;

    }




    return 0;
}