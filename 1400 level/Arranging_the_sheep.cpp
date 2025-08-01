#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(a==0) return b;
    
    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> v;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='*') v.push_back(i);
        } 
        if(v.size() == 0) cout << 0 << '\n';
        else if(v.size()%2==0){
            ll s1=0 , cmp1=0 , ct=v[(v.size()/2)-1]-1;

            for(ll i=0;i<(v.size()/2-1);i++){
                cmp1+= ct; ct--;
                s1+=v[i];
            }
            ll s2=0 , cmp2=0;
            ct=v[v.size()/2-1]+1;
            for(ll i=(v.size()/2) ;i<v.size();i++){
                s2+=v[i];
                cmp2+= ct; ct++;
            }

            cout << cmp1-s1 + s2-cmp2 << '\n' ;
        }
        else{
            ll s1=0 , cmp1=0 , ct=v[v.size()/2]-1;

            for(ll i=0;i<(v.size()/2);i++){
                cmp1+= ct; ct--;
                s1+=v[i];
            }
            ll s2=0 , cmp2=0;
            ct=v[v.size()/2]+1;
            for(ll i=(v.size()/2) + 1;i<v.size();i++){
                s2+=v[i];
                cmp2+= ct; ct++;
            }

            cout << cmp1-s1 + s2-cmp2 << '\n' ;
        }
    }




    return 0;
}