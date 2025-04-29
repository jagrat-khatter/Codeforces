#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a , ll b)
{
    if(a>b) return b;
    else return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        set<ll> s1,s2;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll x; cin >> x;
                if(x==1) { // now we need to store that this row and column cannot be used
                    s1.insert(i+1);    //inserting row 
                    s2.insert(j+1);    //inserting column
                }
            }
        }
        ll r=0,c=0;
        r = n - s1.size() ; // number of empty rows  
        c = m - s2.size() ; // number of empty columns
        //cout << r << ' ' << c << '\n';
        ll ans = min(r,c);
        if(ans%2 ==0) cout << "Vivek" << '\n';
        else cout << "Ashish" << '\n';
    }


    return 0;
}