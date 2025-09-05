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

    else return (b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
struct Pt {
    ll x,y; 
    void read() {
        cin >> x >> y ;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >>t;
    while(t--)
    {
        Pt p1,p2,p3,p4; p1.read(); p2.read(); p3.read(); p4.read();
        // seeing with respect to line p1-p2
        ll crp1 = (p2.x - p1.x) * (p4.y - p1.y) - (p4.x - p1.x) * (p2.y - p1.y);
        ll crp2 = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
        
        
        // seeing with respect to line p3-p4 
        ll crp3 = (p4.x - p3.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p4.y - p3.y);
        ll crp4 = (p4.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p4.y - p3.y);
        // cout << crp1 << ' ' << crp2 << '\n' ;
        // cout << crp3 << ' ' << crp4 << '\n' ;

        if(crp1==0 && crp2==0 && crp3==0 && crp4==0){// lines are collinear
            if(max(p1.x , p2.x)<min(p3.x,p4.x) || max(p1.y , p2.y)<min(p3.y,p4.y)) cout << "NO" << '\n';
            else if(max(p3.x , p4.x)<min(p1.x,p2.x) || max(p3.y , p4.y)<min(p1.y,p2.y)) cout << "NO" << '\n';
            else cout << "YES\n" ;
        }
        else if((crp1<0 && crp2<0) || (crp1>0 && crp2>0) || (crp3<0 && crp4<0) || (crp3>0 && crp4>0)) cout << "NO\n" ;
        else cout << "YES\n" ;
    }
    

    return 0;
}