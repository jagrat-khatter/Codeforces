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
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x ; cin >> x;
            v.push_back(x);
        }
        ll ct=1 , m=-1;
        vector<ll> v2;
        for(ll i=0;i<n;i++){
            if(v[i]!=m) {v2.push_back(v[i]); m= v[i] ;}
        }
        //for(auto i : v2) cout << i << ' ';
        n = v2.size();
        for(ll i=1;i<n;i++){
            if(i==n-1) ct++;
            else if(v2[i]>v2[i-1] && v2[i]>v2[i+1]) ct++; // local maxima
            else if(v2[i]<v2[i-1] && v2[i]<v2[i+1]) ct++; // local minima
            //cout << ct << '\n';
        }

         cout << ct << '\n' ;
    }


    return 0;
}