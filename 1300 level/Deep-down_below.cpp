#include <bits/stdc++.h>
using namespace std;
using ll  = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<pair<ll ,ll>> final;
        for(ll i=0;i<n;i++){
            ll k ; cin >> k;
            vector<ll> v; 
            ll mx = lmin;

            for(ll j=0;j<k;j++){
                ll e; cin >> e;v.push_back(e-j+1);
                mx = max(mx , e-j+1);
            }

            final.push_back({mx, k});
        }

        sort(final.begin() , final.end());

        //for(auto i : final) cout << i.first << ' ' << i.second << '\n';
        ll init = final[0].first ;
        ll ct = init;
        // final[i].first are the values that hero needs to have at the start of cave only
        //for(auto i : final) cout << i.first << ' ' << i.second << '\n';
        for(ll i=0;i<n;i++){
            if(ct >= final[i].first){
                ct+= final[i].second;
            }
            else{
                ll df = final[i].first - ct;
                init += df;
                ct += df; // making the init in order that hero has 

                ct += final[i].second;
            }

        }

        cout << init << '\n';
    }



    return 0;
}