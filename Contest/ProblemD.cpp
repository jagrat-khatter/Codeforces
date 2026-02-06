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
        ll n,k ; cin >> n >> k;
        vector<ll> v(n+1); 
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        set<ll> s1={v[1]+k+1},s2={v[1]-k-1};

        ll ct=0;
        for(ll i=2;i<=n;i++){
            ll ans=0;
            if(s1.size()){
                
                if(v[i]>=*(s1.begin())) ans=1;
                else if(v[i]<=*(--s2.end())) ans=1;
            }
            if(ans==1) {
                //cout << i << '\n' ;
                ct++; s1.clear(); s2.clear(); 
            }

            if(ans==0){
                s1.insert(v[i]+k+1); s2.insert(v[i]-k-1);
            }
        }

        cout << ct << '\n' ;
    }




    return 0;
}