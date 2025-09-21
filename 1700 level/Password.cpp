#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2)%MOD;
    if(e%2==0) return (value*value)%MOD;
    else return ((value*value)%MOD* (b%MOD))%MOD;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    ll n=s.size();
    // making hash for this
    vector<ll> pf;
    ll h=0; 
    for(auto i : s){
        h = ((31*h)%MOD + (i - 'a' + 1)%MOD)%MOD ;
        pf.push_back(h);
    }
    vector<pair<ll,ll>> v; 
    string str="";
    
    for(ll i=0;i<n-1;i++){
        str += s[i];
        ll r=n-1-i;
        ll sz = i+1;
        ll hs1 = pf[sz-1]%MOD; 
        ll hs2 = (pf[n-1]%MOD-(pf[n-1-sz]*power(31 , sz))%MOD +MOD)%MOD ;
        if(hs1 == hs2) v.push_back({sz , hs1});
        // cout << i <<  ' ' << str << ' '<< r <<'\n' ;
    }

    sort(v.begin() , v.end());
    // for(auto i  : v) cout << i.first << ' ' << i.second << '\n';
    ll l=0-1 , r=v.size()-1+1;
    while(r-1 > l){
        ll mid = (l+r)/2;
        // we need to calculate hash of this string
        ll hsh= v[mid].second;
        bool status = false;
        ll sz = v[mid].first;
        for(ll i=sz;i<n-1;i++){
            ll hsq = (pf[i]%MOD  - (pf[i-sz]*power(31 , sz))%MOD + MOD)%MOD;
            if(hsq == hsh) {status=true; break;}
        }

        if(status) l=mid;
        else r=mid;
    }
    //cout << v[l].first<< '\n';
    if(l!=-1) {
        ll sz = v[l].first;
        ll hsh = v[l].second;
        for(ll i=sz;i<n-1;i++){
            ll hsq = (pf[i]%MOD  - (pf[i-sz]*power(31 , sz))%MOD + MOD)%MOD;
            if(hsq == hsh) {
                for(ll j=i-sz+1;j<=i;j++){
                    cout << s[j];
                }
                cout << '\n';
            break;}
        }
    }
    else cout << "Just a legend" << '\n';


    return 0;
}