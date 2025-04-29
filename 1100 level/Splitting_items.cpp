#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll comparator(ll a, ll b)
{
    return a>b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , k; cin >> n >> k;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x; v.push_back(x);
        }
        sort(v.begin() , v.end() , comparator) ;
        // at even position you have to manipulations
        for(ll i=0;i<n && k>0;i++)
        {
            if((i)%2!=0) { 
                if(k-(v[i-1] -v[i])>=0) {k -= v[i-1] -v[i]; v[i]=v[i-1] ;} // demand for increase is less than supply by k
                else {v[i] += k ; k=0;} // demand for increase is more than supply by k
            } 
        }
        ll ans =0;
        for(ll i=0;i<n;i++)
        {
            if(i%2==0) ans += v[i];
            else ans -= v[i];
        }
        cout << ans <<'\n' ;
    }


    return 0;
}