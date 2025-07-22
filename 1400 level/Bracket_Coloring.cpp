#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);

    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

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

    ll t; cin>> t;
    while(t--){
        ll n; string s; cin >> n;
        cin >> s;
        // ( => +1    and   ) => -1
        // first iterate through all the strings to check if the sum is 0 or not 
        // or if the whole string is beautiful or reverse of whole string is beautiful

        ll c1=0 , c2=0;
        
        for(auto i : s) {
            if(i=='(') c1++;
            else c2++;
        }
        ll id=0;
        map<ll , ll> mp;
        if(c1==c2) {
            c1=0 , c2=0;
            if(s[0]=='(') c1++;
            else c2++;
            ll lst=0;
            ll f1=0 , f2=0;
            for(ll i=1;i<n;i++){
                if(c1 > c2) f1=1;
                if(c2 > c1) f2=1;
                

                if(s[i]=='(') c1++;
                else c2++;
                //cout << i << ' ' << c1<<' ' <<  c2 << '\n' ;
                
                if(c1==c2){
                    for(ll j=lst;j<=i;j++){
                        if(f1) mp[j]=1;
                        else mp[j]=2;
                    }
                    f1=0 , f2=0; c1=0; c2=0;
                    lst=i+1;
                }
            }

            ll cc1=0 , cc2=0;
            for(ll i=0;i<n;i++){
                if(mp[i]==1) cc1=1;
                else cc2=1;
            }
            if(cc1 && cc2) {
                cout << 2 << '\n';
                for(ll i=0;i<n;i++) cout << mp[i] << ' ';
            }
            else {
                cout <<1 << '\n' ;
                for(ll i=0;i<n;i++) cout << 1 << ' ';
            }
            cout << '\n' ;
        }
        else cout << -1 << '\n' ;
    }


    return 0;
}