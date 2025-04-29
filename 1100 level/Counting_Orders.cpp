#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD  = 1e9 + 7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> a,b;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            a.push_back(x);
        }
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            b.push_back(x);
        }
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        
        ll status=0 ,ans =1 , id=a.size()-1 , e=0;
        for(ll i=b.size()-1;i>=0;i--)
        {
            // for this element we'll search number of elements greater than it
            
            ll j;
            for(j=id;j>=0;j--)
            {
                if(a[j]>b[i]) e++;
                else break;
            }
            id = j;
            if(e!=0)
            {
                ans = (ans * e)%MOD; e--;
            }
            else {status = 1; break;}
        }
        if(!status) cout << ans << '\n';
        else cout << 0 << '\n' ;  
    }


    return 0;
}