#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,x,y; cin >> n >> x>> y;
        ll s1,s2;
        
        s1 = n/x;
        s2 = n/y;
        
        ll cm= n / lcm(x,y);
        
        //cout << cm << '\n';
        ll n1 = s1 - cm;  // Things we have to add
        ll n2 = s2 - cm;  // Things we have to subsract
        //cout << n1 << ' ' << n2 << '\n';
        ll ans=0;
        
        ans +=( (n1)*(2*n+(n1-1)*(-1)) ) / 2;
        ans -= (n2 * (n2 + 1) )/ 2;
        cout << ans << '\n' ;
    }



    return 0;
}