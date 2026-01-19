#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
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
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
}
bool isPalindromic(ll n){
    vector<ll> v; v.push_back(0);
    while(n){
        v.push_back(n%10); n /= 10;
    }
    bool ans=true;
    ll sz = v.size()-1;
    for(ll i=1;i<=(sz)/2;i++){
        if(v[i] != v[sz-i+1]) ans=false;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> ps;
    ps.push_back(0);
    for(ll i=1;i<=40000;i++){
        if(isPalindromic(i)) ps.push_back(i);
    }

    //cout << ps.size() ;
    vector<vector<ll>> dp((4*1e4)+1 , vector<ll> (ps.size() , 0));

    for(ll i=1;i<ps.size();i++){
        dp[0][i]=1;
        for(ll j=1;j<=(4*1e4);j++){
            if(i==1) dp[j][i]=1;
            else {
                dp[j][i] =0;
                dp[j][i] = (dp[j][i] + dp[j][i-1])%MOD;
                if(j - ps[i] >= 0) dp[j][i] = (dp[j][i] + dp[j - ps[i]][i])%MOD;
            }
        }
        
    }


    

    // if we do 
    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;

        cout << dp[n][498] << '\n';
    }


    return 0;
}