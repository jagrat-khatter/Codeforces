#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
        vector<ll> v(n+1);
        set<ll> s;
        for(ll i=1;i<=n;i++){
            s.insert(i);
        }
        ll tmp;
        
        while(s.size()){
            ll fs , cfs;
            while(cfs != *(s.begin())){cout <<"? " <<  *(s.begin()) << endl;
            cin >> cfs;}
            fs = cfs;
            cout <<"? " << fs << endl;
            ll res; cin >> res;
            s.erase(fs);
            v[cfs]=res;
            
            while(res!=fs){
                s.erase(res);
                cout << "? " << fs << endl;
                cfs = res;
                cin >> res;
                v[cfs] = res;
            }
        }
        cout << '!' <<' ';
        for(ll i=1;i<=n;i++){
            cout << v[i] << ' ';
        }
        cout << endl ;
    }


    return 0;
}