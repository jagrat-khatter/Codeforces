#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool parity(ll a, ll b) // if both have same parity return 0 else returns 1
{
    bool p = (a%2==0) ;
    bool q = (b%2==0) ;
    if(p && q) return 0;
    else if(!p && q) return 1;
    else if(p && !q) return 1;
    else return 0;
}
ll max(ll a, ll b)
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
        ll n ; cin >> n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin >> v[i];

        ll l=0 , r=0 , ans = lmin;
        while(r<n)
        {
            if(( r==n-1 || parity(v[r] , v[r+1])==0)){
                
                vector<ll> p;
                ll m = r - l +1;
                for(ll i=l;i<=r;i++)
                {
                    if(i==l) p.push_back(v[i]);
                    else p.push_back(p[i-l-1] + v[i]);
                }
                // for(ll i=0;i<m;i++){
                //     cout << p[i] <<' ';
                // }
                set<ll> s;
                // cout << '\n';
                
                for(ll i=m-1;i>=0;i--)
                {
                    ll e=p[i];
                    if(s.size()==0) ans = max(ans , e);
                    else ans = max(ans , *(--s.end()) - e);
                    s.insert(e);
                }
                ans = max(ans , *(--s.end()) - 0);

                // cout << l << ' ' << r <<'\n';
                if(r != n-1 ) l= r+1;
                
            }
            r++;
        }
        cout << ans << '\n' ;
        
    }



    return 0;
}