#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,d; cin >> n >> d;
    vector<ll> v(n);
    for(auto &i : v) cin >> i;
    ll ans = 0;
    for(ll i=0;i<n-2;i++){

        ll l=i-1 , r=n-1+1;
        while(r-1>l)
        {
            ll mid = (l+r)/2;
            if(v[mid]-v[i]<=d) l = mid;
            else r = mid;
        }
        //cout << i << ' ' << l << '\n'; // here l will give the last true 
        if(l - i>1){
            ll q = l-i-1;
            ans += q * (q+1) / 2;
        }
    }


    cout << ans<< '\n';
    



    return 0;
}