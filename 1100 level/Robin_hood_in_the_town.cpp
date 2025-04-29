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
        ll n , sum=0; cin >> n;
        vector<ll> v;

        for(ll i=0;i<n;i++){
            ll x;cin >> x;
            v.push_back(x);
            sum += x;
        }
        if(n==1 || n==2) {cout << -1 << '\n' ; continue;}
        sort(v.begin() , v.end());

        // now we need to find the element with at the middle+1 
        // for 0 based indexing 6 elements - index(3) |||  7 elements - index(3)
        ll e = v[n/2];

        ll ans = e * n * 2 - sum;
        if(ans<0) cout << 0 << '\n';
        else cout << ans + 1<< '\n';


    }



    return 0;
}