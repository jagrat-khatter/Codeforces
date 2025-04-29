#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll max (ll a, ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n , k , wsum=0; cin >> n >> k;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
        {
            cin >> v[i];
            wsum += v[i];
        }
        sort(v.begin() , v.end());
        // now making two arrays for front and back 
        vector<ll> f,b;
        ll s=0;
        for(ll i=2*k-1;i>=0;i--)
        {
            s += v[i];
            if(i%2==0){
                b.push_back(s);
                s=0;
            }
        }
        for(ll i=n-k;i<n;i++)
        {
            f.push_back(v[i]) ;
        }
        // now aking these array as prefix sum
        for(ll i=1;i<k;i++)
        {
            f[i]=f[i]+f[i-1];
            b[i]=b[i]+b[i-1];
        }
        // for(ll i=0;i<k;i++) cout << f[i] << ' ';
        // cout << '\n';
        // for(ll i=0;i<k;i++) cout << b[i] << ' ';
        // cout << '\n' ;
        ll rsum = wsum - f[k-1] - b[k-1];
        //cout << rsum << '\n' ;
        ll sum , ans  = lmin ;
        for(ll i=0;i<=k;i++) // now making all the combinations of back pairs and front elements
        {
            // i reprsents the number of front elements and k-i represents number of back elements
            if(i==0) sum = b[k-1];
            else if(i==k) sum = f[k-1];
            else sum = f[i-1] + b[(k-i)-1] ;

            ans = max(ans , sum) ;
        }
        cout << ans + rsum<< '\n';
    }



    return 0;
}