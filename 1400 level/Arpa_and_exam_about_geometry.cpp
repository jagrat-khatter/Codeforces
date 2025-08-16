#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    
    return gcd(b ,a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ld ax,ay,bx,by,cx,cy; cin >> ax>>ay>>bx>>by>>cx>>cy;
        // cout << ax/ay << ' ' << ax ;

        cout << fixed;
        

        ld a1,b1,c1 , a2,b2,c2;
        a1 = 2*ax - 2*bx; b1 = 2*ay - 2*by; c1 = ax*ax + ay*ay - bx*bx - by*by;

        a2 = 2*bx - 2*cx; b2 = 2*by - 2*cy; c2 = bx*bx + by*by - cx*cx - cy*cy;
        
        //cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << a2 <<' ' << b2 << ' ' << c2 << '\n' ;
        ld s1 , s2 ;
        if((a1==0 && a2==0) || (b1==0 && b2==0)) {cout << "NO" << '\n';continue;}
        
        if(a2==0) s1=lmax;
        else s1 = a1/a2;

        if(b2==0) s2=lmax;
        else s2 = b1/b2;
        if(s1==s2) {cout << "NO" << '\n';continue;}
        //cout << "Circle" << '\n' ;

        ll ans1 = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
        ll ans2 = (bx-cx)*(bx-cx) + (by-cy)*(by-cy);
        if(ans1==ans2) cout << "YES" << '\n';
        else cout << "NO" <<'\n';
    }


    return 0;
}
