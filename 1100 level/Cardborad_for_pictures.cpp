#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
bool predicate_func(vector<ll> const  &v ,ll mid , ll c)
{
    ll sum =0;
    for(ll i=0;i<v.size();i++)
    {
        sum += (v[i]+mid) * (v[i]+mid) ;
        if(sum>c) break;
    }
    if(sum<=c) return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n, c; cin >> n >> c;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        // we'll do binary search on (twice the widh of frame)
        ll l=1-1,r=1000000000 ;  // the longest width can be r , when c= 10^18 and there is only 1 picture with size 1 
        while(r-1>l)
        {
            ll mid = (l+r)/2;
            if(predicate_func(v , mid , c)) l=mid;
            else r=mid;
        } 
        cout << l/2 << '\n'  ; // we are outputing l/2 bcoz the mid is 2*(width of frame)
    }



    return 0;
}