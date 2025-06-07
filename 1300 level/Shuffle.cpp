#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
        ll n,x,m ; cin >> n >> x >> m;
        bool fg = false;
        ll l , r;
        for(ll i=1;i<=m;i++){ // here ith operation 
            ll a,b; cin >> a >> b;
            if(a>b) {
                b = a+b;
                a = b-a;
                b = b-a;
            }
            if(fg){
                if(l>=a){
                    if(b>=l) {r=max(r , b); l = a;}
                }
                else{
                    if(a<=r) {r=max(r , b);}
                }
            }
            else{
                if(x>=a && x<=b) fg = true;
                l = a; r = b;
            }

            //if(fg) cout << i << ' ' <<l << ' ' << r << '\n';
        }

        if(fg) cout << r - l +1 << '\n';
        else cout << 1 << '\n';
    }




    return 0;
}