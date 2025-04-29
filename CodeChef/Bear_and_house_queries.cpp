#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    // for finding point p
    ll l = 0-1 , r= 1000+1;     // binary search on x-axis
    while(r-1>l)
    {
        ll mid = (l+r)/2;
        cout << '?' << mid << ' ' << 0 ;
        string  x ; cin >> x;
        if(x== "YES") l= mid;
        else r= mid;
    }
    ll p1x=l , p1y = 0;      // binary search parallel to x-axis
    // for finding point f
    l = p1x ; r=1000+1 ; // The base of the triangle is longer that the side of the square.
    while(r-1>l)
    {
        ll mid=(l+r)/2;
        cout << '?' << mid << ' ' << 2*p1x;
        string x; cin >> x;
        if(x== "YES") l= mid;
        else r= mid;
    }
    ll p2x = l , p2y = 2*p1x;
    // for finding q
    l = p2y ; r=1000+1;    // binary search on y axis
    while(r-1>l)
    {
        ll mid=(l+r)/2;
        cout << '?' << 0 << ' ' << mid ;
        string x ; cin >> x;
        if(x=="YES") l = mid;
        else r = mid;
    }
    ll p3x = 0 , p3y = l;

    cout <<'!'<< (p2y * p2y ) + (p2x * (p3y-p2y)) ;




    return 0;
}