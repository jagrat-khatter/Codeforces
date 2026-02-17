#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double ;
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
    for(auto j : v) cerr << j << " ";
    cerr << "]\n" ; return ;
}
ll pr1(ll n){// no of ways to make n if no carry is to be produced
    if(n==0) return 1;
    return (n+1);
}
ll pr2(ll n){// no of ways to make n if a carry is to be produced
    if(n==0) return 9;
    else if(n==9) return 0;
    else return 8 - (n) + 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        while(n){
            v.push_back(n%10) ; n/= 10;
        }
        v.push_back(0);
        reverse(v.begin() , v.end());
        vector<vector<ll>> dp(v.size(), vector<ll> (2 , 0));
        dp[0][0] = 1;

        for(ll i=1;i<=v.size()-1;i++){
            ll e = v[i];
            // if i=1 && i=2 we dont want them to produce a carry
            if(i<=2){
                ll val;
                if(e==0) val=9;
                else val=e-1;
                dp[i][0] = pr1(e);
                if(e!=0) dp[i][1] = pr1(val);
                else dp[i][1] = 0;// in this case we have to produce a carry so we avoid 
            }
            else if(i>=v.size()-1-1){
                dp[i][1]=0;
                dp[i][0] = (pr1(e)*dp[i-2][0] + pr2(e)*dp[i-2][1]) ;
            }
            else {
                ll val;
                if(e==0) val=9;
                else val=e-1;
                if(e!=0) dp[i][1] = (pr1(val)*dp[i-2][0] + pr2(val)*dp[i-2][1]) ;
                else dp[i][1] = pr1(val)*dp[i-2][1];
                dp[i][0] = (pr1(e)*dp[i-2][0] + pr2(e)*dp[i-2][1]) ;
            }
            
            //cout << i <<' ' <<dp[i][0] << ' ' << dp[i][1] << '\n' ;
        }

        cout << (dp[v.size()-1][0] * dp[v.size()-2][0]) - 2 << '\n'; // the answer will include two cases where 
    }






    return 0;
}