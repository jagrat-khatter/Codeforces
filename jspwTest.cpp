#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gdc(ll a,ll b){
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
        vector<ll> v;

        ll id=0;
        for(ll i=0;i<n;i++){
            ll x; cin >> x; v.push_back(x);if(x!=0) id=i;
        }
        if(v[id]>0) {cout << "NO\n" ; continue;}
        
        ll dwn;
        //cout << id << '\n';
        bool ans=true;
        for(ll i=id;i>=0;i--){
            if(i==id) dwn = abs(v[id]);
            else if(i!=0) {
                dwn = v[i] - dwn;
                if(dwn>=0) {ans=false; break;}
                dwn = abs(dwn);
            }
            else if(i==0 && dwn!=v[0]) {ans=false; break;}
        }

        cout << (ans==true ? "YES\n" : "NO\n") ;


    }




    return 0;
}