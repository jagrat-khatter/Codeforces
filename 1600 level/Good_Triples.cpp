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
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> pr0(10),pr1(10),pr2(10);
    // to make n with 3 non negative integers such that no carry is produced
    // to make n with 3 non negative integers such that 1 carry is produced
    // to make n with 3 non negative integers such that 2 carry is produced
    for(ll i=0;i<=9;i++){
        for(ll j=0;j<=9;j++){
            for(ll k=0;k<=9;k++){
                ll temp = (i+j+k);
                if(temp<10) pr0[temp%10]++;
                else if(temp<20) pr1[temp%10]++;
                else pr2[temp%10]++;
            }
        }
    }
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        while(n){
            v.push_back(n%10); n /= 10; 
        }
        v.push_back(0);
        reverse(v.begin() , v.end());
        vector<vector<ll>> dp(v.size() , vector<ll> (3 , 0));
        
        ll ans=1;
        // at each place we want no carry to be generated else sum of digits will be lost
        for(ll i=1;i<v.size();i++){
            ans *= pr0[v[i]] ;
        }

        cout << ans << '\n' ;

    }




    return 0;
}