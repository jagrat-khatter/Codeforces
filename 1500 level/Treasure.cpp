#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return ((e%2==0) ? 1 : b);
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
        string s; cin >> s;
        ll c1=0,c2=0,c3=0,id; // c1 for ( c2 for ) and c3 for # 
        for(auto i : s){
            if(i=='(') c1++;
            else if(i==')') c2++;
            else c3++;
        }
        if(c2+c3 > c1)  cout << -1 << '\n';
        else {
            ll lst = c1-c2-(c3-1);
            for(ll i=s.size()-1;i>=0;i--){
                if(s[i]=='#') {id=i; break;}
            }
            ll ca=0 , cb=0 , ans=1;
            
            for(ll i=0;i<s.size();i++){
                if(i==id) cb += lst;
                else if(s[i]=='#') cb++;
                else if(s[i]==')') cb++;
                else ca++;

                if(ca<cb) {ans=0; break;}
            }
            if(!ans) cout << -1 << '\n';
            else {
                for(ll i=1;i<=c3;i++){
                    if(i!=c3) cout << 1 << '\n';
                    else cout << lst << '\n';
                }
            }
        }
    }


    return 0;
}