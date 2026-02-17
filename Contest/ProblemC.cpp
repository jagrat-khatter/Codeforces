#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        ll ct=0;
        for(ll i=2;i<=n;i++){
            if((v[i]==1 && v[i-1]==6) || (v[i]==6 && v[i-1]==1) || (v[i]==1 && v[i-1]==1) || (v[i]==6 && v[i-1]==6)){
                if(i+1<=n && (v[i+1]==2 || v[i+1]==5)) v[i]=3;
                else v[i]=5;
                ct++;
            }
            else if((v[i]==2 && v[i-1]==5) || (v[i]==5 && v[i-1]==2) || (v[i]==5 && v[i-1]==5) || (v[i]==2 && v[i-1]==2)){
                if(i+1<=n && (v[i+1]==1 || v[i+1]==6)) v[i]=3;
                else v[i]=1;
                ct++;
            }
            else if((v[i]==3 && v[i-1]==4) || (v[i]==4 && v[i-1]==3) || (v[i]==3 && v[i-1]==3) || (v[i]==4 && v[i-1]==4)){
                if(i+1<=n && (v[i+1]==1 || v[i+1]==6)) v[i]=5;
                else v[i]=1;
                ct++;
            }
        }

        cout << ct << '\n' ;
    }




    return 0;
}