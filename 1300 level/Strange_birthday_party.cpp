#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
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
        vector<ll> v1(n) , v2(m);
        for(auto &i : v1) cin >> i;
        for(auto &i : v2) cin >> i;

        sort(v1.begin() , v1.end());
        ll l=0 , cst=0;
        for(ll i=v1.size()-1;i>=0;i--)
        {
            ll e= v1[i];
            if(v2[l] < v2[e-1]) {
                cst += v2[l]; // gift paid
                l++;
            }
            else if(v2[l] >= v2[e-1]){
                cst += v2[e-1]; // cash paid
            }
        }

        cout << cst << '\n';
    }



    return 0;
}