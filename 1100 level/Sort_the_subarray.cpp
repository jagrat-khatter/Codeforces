#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ;cin >> n;
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++)  cin >> a[i];
        for(ll i=0;i<n;i++) cin >> b[i];

        ll l=0,r=n-1,lf=0,rf=n-1 , min = LLONG_MAX , max =LLONG_MIN;
        for(ll i=0;i<n;i++)
        {
            if(a[i]!=b[i]) l = i;
        }
        for(ll i=n-1;i>=0;i--)
        {
            if(a[i]!=b[i]) r = i;
        }
        for(ll i=l;i<=r;i++)
        {
            if(b[i]>max) max = b[i];
            if(b[i]<min) min = b[i];
        }
        // now we have l and r in our hands now we need to find lf and rf , lf<=l and rf>=r
        if(l>0) 
        {
            if(b[l-1]<=min){
                
                for(ll j=l-1;j>=0;j--)
                {
                    if(b[j]>b[j+1]) break;
                    lf = j;
                }
            }
            else lf = l;
        }

        if(r<n-1)
        {
            if(b[r+1]>=max){
                
                for(ll j=r+1;j<n;j++)
                {
                    if(b[j]<b[j-1]) break;
                    rf = j;
                }
            }
            else rf = r;
        }
        cout << lf+1 << ' ' << rf+1 << '\n' ; // making one based indexing
    }


    return 0;
}