#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
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
        ll n,kx,ky,dx,dy; cin >>n>> kx>> ky>> dx>>dy;
        if(kx==dx){
            if(ky<dy) cout << dy ;
            else cout<< n-dy ;
        }
        else if(ky==dy){
            if(kx<dx) cout << dx ;
            else cout << n-dx;
        }
        else if(kx<dx && ky<dy){
            cout << max({dx,dy});
        }
        else if(kx>dx && ky>dy){
            cout << max({n-dx , n-dy});
        }
        else if(kx>dx && ky<dy){
            cout << max({n-dx , dy});
        }
        else if(kx<dx && ky>dy){
            cout << max({dx , n-dy});
        }
        cout << '\n';
    }




    return 0;
}