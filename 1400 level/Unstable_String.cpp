#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
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
        string s ; cin >> s;ll n = s.size();
        ll l=0 , r=0 , ans=0;
        while(s[r]=='?') r++;
        // now either r is 0 or 1
        char trm = s[r];
        if(r==n || r==n-1 || n==1) {cout << n * (n+1)/2 << '\n'; continue;}
        for(ll i = r+1 ;i<n;i++){
            if((trm=='0' && (s[i]=='1' || s[i]=='?')) || (trm=='1' && (s[i]=='0' || s[i]=='?'))) {
                if(trm=='0') trm='1'; // even if s[i]==? we want to make sure that terms flip
                else trm='0';
            }
            else{
                ans += (r-l+1) * (r-l+2) / 2;
                if(s[i-1]!='?'){
                    l=i;
                    trm = s[i];
                }
                else {
                    //cout << i << '\n' ;
                    l=i;
                    ll ct=0;// we want to measur ehow many ? are used 
                    while(s[l-1]=='?' && l-1>=0) {l--;ct++;}
                    ans -= ct*(ct+1) / 2;
                    //cout << l << '\n' ;
                    trm = s[i];
                }
            }
            if(i==n-1){
                ans += (i-l+1) * (i-l+2) / 2;
            }

            r=i; // r is pointing to just past index i when loop will opearate

        }

        cout << ans << '\n' ;
    }

    

    

    return 0;
}