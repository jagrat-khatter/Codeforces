#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
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
        ll w,h ; cin >> w >> h;
        ll x1,y1,x2,y2 ; cin >> x1 >> y1 >> x2 >> y2 ;
        ll sx = x2-x1  , sy = y2-y1; // dimensions of main box
        ll rx , ry ; cin >> rx >> ry ; // dimensions of second box
        if(rx > w - sx && ry > h - sy) cout << -1 << '\n';
        else if(rx <= w    &&    rx > w-sx    &&    ry <= h - sy) {
            if(max(h - y2 , y1 - 0) >= ry) cout << 0 << '\n';
            else cout << ry - max(h - y2 , y1 - 0) << '\n';
        }
        else if(ry <= h    &&    ry > h-sy   &&   rx <= w - sx) {
            if(max(x1-0 , w-x2) >= rx) cout << 0 << '\n';
            else cout << rx - max(x1-0 , w-x2) << '\n';
        }
        else if(ry <= h-sy && rx <= w-sx){
            ll ans=0;
            if(max(x1-0 , w-x2) >= rx || max(h - y2 , y1 - 0) >= ry) cout << 0 << '\n';
            else
            {cout << min(ry - max(h - y2 , y1 - 0) , rx - max(x1-0 , w-x2)) << '\n';}
        
        }
    }



    return 0;
}