#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ll> v1(n) , v2(n);
        vector<ll> s1(n) , s2(n);
        for(auto &i : v1) cin >> i;
        for(auto &i : v2) cin >> i;

        
        for(ll i=n-1;i>=0;i--){
            if(i==n-1) {
                s1[i]=v1[i];
                s2[i]=v2[i];
            }
            else
            {s1[i]=s2[i+1]+v1[i];
            s2[i]=s1[i+1]+v2[i];}
            
            
        }
        ll ans=0;
        ll ptr;
        if(s1[0]>s2[0]) ptr=1;
        else ptr=2;
        bool sk = false;
        for(ll i=0;i<n;i++){
            if(i!=n-1 && ptr==1 && s1[i+1]>s1[i]) sk = true;// ptr remains unchanged
            else if(i!=n-1 && ptr==2 && s2[i+1]>s2[i]) sk = true;// ptr remains unchanged
            
            if(ptr==1 && !sk) {ans+=v1[i];ptr=2;}
            else if(ptr==2 && !sk) {ans+=v2[i];ptr=1;}
            sk = false;
        }
        cout << ans << '\n' ;
    }


    return 0;
}