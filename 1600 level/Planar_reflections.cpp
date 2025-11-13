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
        ll n,k ; cin >> n >> k;
        vector<vector<vector<ll>>> arr(n+2 , vector<vector<ll>> (k+1 , vector<ll> (2+1 , 0)));// we'll use n from 0 to n+1 1
        
        // we'll use k from 0 to k // we'll use direction 0(right) 1(left)
        
        for(ll j=0;j<=n+1;j++){ // special base case when decay age of initial particle is 1
            arr[j][1][1]=1;
            arr[j][1][0]=1;// when decay health is 1 from whichever wall it hits
        }

        // 
        for(ll i=2;i<=k;i++){ // when decay age of initial particle is i 
            arr[n+1][i][0]=1;
            arr[0][i][1]=1;
            for(ll j=n;j>=1;j--){
                arr[j][i][0]= (arr[j-1][i-1][1] + arr[j+1][i][0])%MOD;
            }

            for(ll j=1;j<=n;j++){
                arr[j][i][1]= (arr[j-1][i][1] + arr[j+1][i-1][0])%MOD;
            }
        }

        cout << arr[1][k][0]%MOD << '\n' ;
        
        
        
    }




    return 0;
}