#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto i : v) cerr << i << " ";
    cerr << "] \n" ;
}
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

    ll n; cin >> n;
    vector<vector<ll>> v(n+1 , vector<ll> (n+1) );
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin >> v[i][j];
        }
    }

    ll mx = power(2 , n);
    vector<set<ll>> msk(n+1);// the number of bits set in the bitmask 
    for(ll mask=0;mask<mx;mask++){
        msk[__builtin_popcountll(mask)].insert(mask);
    }

    
    vector<ll> dp(power(2,n)) ;
    dp[0] = 1;
    for(ll sb=1;sb<=n;sb++){
        for(auto mask : msk[sb]){

            ll ct=0;

            for(ll i=0;i<n;i++){
                if((mask>>i & 1) && (v[i+1][sb])) {
                    ct= (ct + dp[mask - power(2,i)])%MOD;
                }
            }
            dp[mask] = (ct%MOD);
            //cout << sb << ' ' << mask << ' ' << dp[mask] << '\n';
        }
    }

    cout << dp[mx-1] << '\n' ;


    return 0;
}