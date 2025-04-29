#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll max(ll a, ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ,k ; cin >> n >> k;
        vector<ll> v(n);
        set<ll> s;
        for(ll i=0;i<n;i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size()<k) cout << n << '\n';

        else if(v[0]!=v[n-1]){
            ll p , q;
            for(ll i=1;i<n;i++)
            {
                if(v[i] != v[0]) {
                    p = i;
                    break;
                }
            }
            for(ll i=n-2;i>=0;i--)
            {
                if(v[i] != v[n-1])
                {
                    q=i;
                    break;
                }
            }
            cout << max(n-p , q+1) << '\n';
        }
        else{
            ll p , q;
            for(ll i=1;i<n;i++)
            {
                if(v[i] != v[0]) {
                    p = i;
                    break;
                }
            }
            for(ll i=n-2;i>=0;i--)
            {
                if(v[i] != v[n-1])
                {
                    q=i;
                    break;
                }
            }
            ll a1 = n-p - (n-1-q);
            for(ll i=p;i<n;i++)
            {
                if(v[i] != v[p]) {
                    p = i;
                    break;
                }
            }
            for(ll i=q;i>=0;i--)
            {
                if(v[i] != v[q])
                {
                    q=i;
                    break;
                }
            }
            ll a2 = n-p;
            ll a3 = q+1;
            cout << max(a1,max(a2,a3)) << '\n';
        }

    }


    return 0;
}