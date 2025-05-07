#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin= LLONG_MIN;
const ll lmax = LLONG_MAX;
bool func(ll l , ll r , ll n){ // function to check whether index before l and index after r exist or not
 // 0, 1, 2, 3,  ..... n-2, n-1
    if(l>0 && r<n-1) return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto &i : v){
            ll x;cin >> x;
            i=x;
        }
        ll l=0,r=n-1,fg=0;
        ll mx=n,mn=1;
        while(l<=r){
            if(v[l]==mx || v[l]==mn || v[r]==mx || v[r]==mn){
                if(v[l]==mx) {l++;mx--;} // now that mx is not included in range
                else if(v[l]==mn) {l++;mn++;} // now that mn is not included in range

                if(v[r]==mx) {r--;mx--;}
                else if(v[r]==mn) {r--;mn++;}
            }
            else {cout << l+1 << ' ' << r+1 << '\n';fg=1;break;} // to make indexing 1 based

        }
        if(!fg) cout << -1 << '\n' ;
    }

    return 0; 
}