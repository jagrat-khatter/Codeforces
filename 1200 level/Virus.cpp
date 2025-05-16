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
        ll n,m ; cin >> n >> m;
        // first we have a vector which should have addresses of infected houses 
        vector<ll> ad;
        for(ll i=0;i<m;i++){
            ll x; cin >> x; ad.push_back(x);
        }
        sort(ad.begin() , ad.end());
        vector<ll> nd; // number of uninfected houses in a segment 
        for(ll i=0;i<m-1;i++){
            nd.push_back(ad[i+1] - ad[i] - 1);
        }
        if(ad[0] - 1 + n - ad[m-1]) nd.push_back(ad[0] - 1 + n - ad[m-1]);
        sort(nd.begin() , nd.end());
        ll l=nd.size() - 1;
        ll ans =0 , t=0;
        while(l>=0){
            ll real = nd[l] - 2 * t;
            //cout << real << '\n';
            if(real<= 0) break;
            if(real==1 || real==2) {ans += 1; t++;}
            else {ans += real-1 ; t+=2; }
            l--;
        }
        cout << n-ans << '\n' ;

    }


    return 0;
}