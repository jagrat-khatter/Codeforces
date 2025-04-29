#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmxa = LLONG_MAX;
ll max(ll a,ll b)
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
        ll n ; cin >> n;
        string s;
        cin >> s;

        ll ans = 1 , m = lmin;
        ll l=0,r=s.size()-1;
        if(s[0]=='1' && s[n-1]=='1')
        {
            for(ll i=0;i<n;i++)
            {
                if(s[i]=='0') break;
                l=i;
            }
            for(ll i=n-1;i>=0;i--)
            {
                if(s[i]=='0') break;
                r=i;
            }
            m = max(m , (l+1)+(n-r)) ;
            ll ct=0;
            for(ll i=l+1;i<r;i++)
            {
                if(s[i]!='1')
                {
                    m = max(m , ct);
                    ct=0;
                }
                else ct++;
            }
        }
        else 
        {   ll ct=0;
             for(ll i=0;i<n;i++)
            {
                if(s[i]!='1' || i==n-1)
                {
                    if(i==n-1 && s[i]=='1') m= max(m , ct+1);
                    else m = max(m , ct);
                    ct=0;
                }
                else ct++;
            }
        }
    }


    return 0;
}