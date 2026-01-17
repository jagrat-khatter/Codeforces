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

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> dg;
        ll cn = n;

        ll od=0,ev=0;
        while(cn){
            dg.push_back(cn%10);
            if((cn%10)%2==0) ev=1;
            else od=1;
            cn /= 10;
        }
        if(n%2==1) cout << 0;
        else if(dg.size()==1 && ev==1) cout << -1 ;
        else if(od==1 && ev==0) cout << 0 ;
        else if(od==1 && ev==1) cout << 1 ;
        else {
            sort(dg.begin() , dg.end());
            ll mx=dg[dg.size()-1];
            ll lst = n%10;
            if(lst - mx < 0) cout << 2 ;
            else cout << 3 ;
        }

        cout << '\n' ;

    }



    return 0;
}