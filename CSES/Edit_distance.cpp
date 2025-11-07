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

    string a,b; cin >> a >> b;
    ll sza=a.size() , szb=b.size();
    vector<ll> dp(szb+1 , 0),curr(szb+1 , 0);

    for(ll j=0;j<=szb;j++){// this is for i=0 means zero elemets are left in first string 
        dp[j]=j;
    }
    
    for(ll i=1;i<=sza;i++){
        curr[0]=i;
        for(ll j=1;j<=szb;j++){
            if(a[i-1]==b[j-1]) curr[j]=dp[j-1];// if elements last elements are equal then just discard
            else {
                curr[j]= 1+dp[j]; // 1 + dp[i-1][j]
                curr[j]= min(curr[j] , 1+curr[j-1]);// 1 + dp[i][j-1]
                curr[j]= min(curr[j] , 1+dp[j-1]);// 1 + dp[i-1][j-1]
            }
        }

        swap(dp , curr);
    }

    cout << dp[szb] ;

    return 0;
}