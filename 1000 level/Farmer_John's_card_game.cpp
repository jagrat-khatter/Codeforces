#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--)
    {
        ll n,m,fg=0; cin >> n >> m;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++)
        {
            vector<ll> a;
            for(ll j=1;j<=m;j++)
            {
                ll x; cin >> x;
                a.push_back(x);
            }
            sort(a.begin() , a.end());
            for(ll j=0;j<a.size()-1;j++)
            {
                if(a[j+1]-a[j] != n) fg=1;
            }
            
            if(!fg){
                v.push_back({a[0] , i+1}) ;
            }
        }
        if(fg==1) cout << -1 ;

        else{
            sort(v.begin() , v.end());
            for(ll i=0;i<v.size();i++)
            {
                cout << v[i].second << ' ';
            }
        }

        cout << '\n' ;
    }
    return 0;
}