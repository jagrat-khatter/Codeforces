#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<vector<char>> v(n+1 , vector<char> (n+1));
        bool status = true;
        for(ll i=1;i<=n && status==true;i++){
            for(ll j=1;j<=n && status==true;j++){
                if(k>0) {v[i][j]='U'; k--;}
                else if(i!=n && j==n) v[i][j]='D';
                else if(i==n && j==n && v[i][j-1]=='U') {status=false;}
                else if(j==1) v[i][j]='R';
                else if(j==n) v[i][j]='L';
                else v[i][j]='R';
            }
        }

        if(status) {
            cout << "YES\n" ;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    cout << v[i][j] ;
                }
                cout << '\n' ;
            }
            
        }
        else cout << "NO\n" ; 
    }



    return 0;
}