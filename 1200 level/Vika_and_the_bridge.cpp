#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll max(ll a,ll b){
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
        ll n,k ; cin >> n >> k;
        vector<pair<ll ,ll>> ans(k+1 , {0,0});        // for storing the maximum distance and its frequency 
        // we'll use one based indexing for accessing elements in ans

        map<ll , ll> scd; // this will store second largest distance for each color
        map<ll , ll> ad;  // previous address for each color

        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            ll e = (i+1) - ad[x] -1 ; // current address - prev. address -1(for jump distance)
            //cout << e << '\n';
            if(ans[x].first!=0){ // there is a distance stored previously
                
                if(e>ans[x].first) {scd[x] = ans[x].first; ans[x].first=e; ans[x].second=1;}
                else if(e== ans[x].first) {ans[x].second++;}
                else if(e>scd[x]) scd[x]=e;
            }
            else {ans[x].first=e; ans[x].second=1;}
            ad[x] = i+1;
            //cout << scd[1] << '\n';
        }
        // now for each color we'll save the last distance
        for(ll i=1;i<=k;i++){
            ll x = i;
            ll e = n - ad[x];
            if(ans[x].first!=0){ // there is a distance stored previously
                if(e>ans[x].first) {scd[x] = ans[x].first; ans[x].first=e; ans[x].second=1; }
                else if(e == ans[x].first) {ans[x].second++;}
                else if(e>scd[x]) scd[x]=e;
            }
            else {ans[x].first=e; ans[x].second=1;}
        }
        ll final = lmax;
        for(ll i=1;i<=k;i++){
            ll x = i;
            if(ans[x].second>1) final = min(final , ans[x].first);
            else final = min(final , max(ans[x].first / 2  ,  scd[x]));
        }
        // for(ll i=1;i<=k;i++){
        //     ll x=i;
        //     cout << ans[x].first << ' ' << ans[x].second << ' ' << scd[x] << '\n';
        // }

        cout << final << '\n' ;

    }


    return 0;
}