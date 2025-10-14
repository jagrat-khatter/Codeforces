#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        ll l=0 , r=n+1;
        vector<ll> v(n+2);
        v[0]=lmax; v[n+1]=lmax;
        while(r-l>1){
            ll mid=(l+r)/2;
            ll p,q;
            if(mid>0 && mid<=n) {cout <<  "? " << mid << endl;
            cin >> p ;v[mid] = p;}
            if(mid-1>0 && mid-1<=n)  {cout << "? " << mid-1 << endl;
            cin >> q ;
            v[mid-1] = q;}
            
            if(v[mid]<v[mid-1]) l=mid;
            else r=mid;
        }
        cout << "! " << l << endl;
         
    }




    return 0;
}