#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        
        vector<ll> v; 
        for(ll i=0;i<n;i++)
        {
            ll x ; cin >> x;
            v.push_back(x);
        }
        if(n==1) {
            cout << 0 << '\n';
            continue;
        }
        vector<ll> e;
        for(ll i=1;i<n;i++)
        {
            if(n%i==0) e.push_back(i);
        }
        ll  max=LLONG_MIN;
        for(ll i=0;i<e.size();i++)
        {
            ll lmax=LLONG_MIN, lmin=LLONG_MAX; // local max and min for every possibilty of number of boxes in the truck
            ll p = e[i] , sum=0; // the numner pf boxes in each truck
            for(ll j=0;j<n;j++)
            {
                sum+= v[j];
                if((j+1)%p==0)
                {
                    if(lmax<sum) lmax = sum; // l min and lmax should be initialized such that they 
                    //can be compared to values of long long range 
                    if(lmin>sum) lmin = sum;
                    sum =0;
                }
            }
            if(max < (lmax - lmin)) max = (lmax - lmin);
        }

        cout << max << '\n';
        
    }


    return 0;
}