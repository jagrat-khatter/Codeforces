#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD  = 1e9+7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
struct Pt {
    ll x,y; 
    void read() {
        cin >> x >> y
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3 ; cin >> x1>>y1>>x2>>y2>>x3>>y3;
        bool orien= false;
        if(x1 > x2){
            // then swap x1 and x2 
            x1 = x1 + x2;
            x2 = x1 - x2;
            x1 = x1 - x2;

            y1 = y1 + y2;
            y2 = y1 - y2;
            y1 = y1 - y2;

            orien = true;
        }
        // cause x2 - x1 should always be positive cause coeff of y should always be positive
        ll cy = (x2 - x1) , cx = (y1 - y2) , cc = (x1 - x2)*y1 + (y2 - y1)*x1 ;

        //cout << cy << ' ' << cx << ' ' << cc << '\n';
        
        if(((y3*cy) + (x3*cx ) + (cc)) == 0) cout << "TOUCH" << '\n';
        else if(((y3*cy) + (x3*cx) + (cc)) > 0 && orien==false) cout << "LEFT" << '\n';
        else if(((y3*cy) + (x3*cx) + (cc)) > 0 && orien==true) cout << "RIGHT" << '\n';
        else if(orien == false) cout << "RIGHT" << '\n' ;
        else cout << "LEFT" << '\n' ;
    }
    

    

    return 0;
}