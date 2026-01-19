#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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


    // finding the number of operations required to reach ai from 1 by give series of operations
    vector<ll> dp(3000+1 , imax);
    dp[1]=0;
    for(ll i=1;i<=3000;i++){
        set<ll> sq;
        for(ll j=1;j<=i;j++){
            sq.insert(i/j);
        }
        for(auto j : sq){
            if(j+i<=3000) dp[j + i] = min(dp[j+i] , dp[i]+1);
        }
    }

    ll t; cin >> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        vector<ll> b(n+1); // transforming the b vector in number of operations required
        for(ll i=1;i<=n;i++){
            ll x; cin >> x; b[i]=dp[x];
            //cout << b[i] << ' ';
        }
        //cout << '\n' ;

        vector<ll> c(n+1);
        for(ll i=1;i<=n;i++){
            cin >> c[i] ;
        }
        // since the cost b[i] are not increasing that fast , we can apply upperbound to k
        // since the maximum cost to convert 1->x x<=3000 is 14
        // so cost should not exceed 14*n 
        k = min(k , 14 * n) ; // the ans for this k and original k will match always 
        vector<ll> prev(k+1 , 0),curr(k+1 , 0);
        for(ll i=n;i>=1;i--){
            for(ll j=0;j<=k;j++){
                if(i==n && j>=b[i]) curr[j]=c[i];
                else if(i==n && j<b[i]) curr[j]=0;
                else {
                    curr[j]=imin;
                    curr[j] = max(curr[j] , prev[j]);
                    if(j>=b[i]) curr[j] = max(curr[j] , prev[j - b[i]] + c[i]);
                } 
            }

            swap(prev , curr);
        }

        cout << prev[k] << '\n';
    }




    return 0;
}