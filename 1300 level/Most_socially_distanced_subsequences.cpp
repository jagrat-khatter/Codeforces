#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin>> n;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;

        vector<ll> f;
        for(ll i=0;i<v.size();i++){ 
            // either the element is last or first or it is local maxima or local minima
            if(i==0 || i==n-1){
                f.push_back(v[i]); 
            }
            else if((v[i-1]>v[i] && v[i]<v[i+1])  ||  (v[i-1]<v[i] && v[i]>v[i+1])) {
                f.push_back(v[i]);
            }
        }
        cout << f.size() << '\n';
        for(auto i : f){
            cout << i << ' ';
        }
        cout << '\n';
    }


    return 0;
}