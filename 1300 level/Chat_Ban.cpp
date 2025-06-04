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
        ll k,x ; cin >> k >> x;
        ll ks = k * (k+1) / 2;
        if(x > 2*ks-k) {cout << 2*k-1 << '\n'; continue ;}
        if(x <ks){
            // do binary search on 1 t o k
            ll l=1-1 , r=k+1; 
            while(r-1>l)
            {

                //cout << l << ' ' << r << '\n';
                ll mid = (l+r)/2;
                ll crrs = mid * (mid+1) / 2;
                if(crrs<x) l = mid; // true condition
                else r = mid;  // false condition
            }
            cout << r << '\n' ;
        }
        else if(x==ks){
            cout << k << '\n';
        }
        else{
            ll l=k+1-1 , r=2*k-1+1;
            x = x - ks ;
            while(r-1 > l)
            {
                ll mid = (l+r) / 2;
                ll crrs = (mid - k) * (3*k - mid -1) / 2;
                if(crrs<x) l = mid;
                else r = mid;
            }
            cout << r << '\n';
        }

    }





    return 0;
}