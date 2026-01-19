#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imax = INT_MAX;
const ll imin = INT_MIN;
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
    for(auto j : v) cerr << j <<' ';
    cerr << "]\n";
}
ll pfSum(ll l,ll r,const vector<ll>& pf){
    return pf[r]-pf[l-1];
}
ll nelements(ll l,const vector<ll>& v){
    return v.size()-l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while(t--){
        ll n,a,b; cin >> n >> a>> b;
        vector<ll> v(n+1 , 0);
        vector<ll> pf(n+1 , 0);

        for(ll i=1;i<=n;i++){
            cin >> v[i];
            pf[i] = pf[i-1] + v[i];
        }
        
        // we have to first find where should capital be at the end 
        // we'll check everytime we conquer that should we move our capital forward for further 
        // attacks to be optimized
        ll cp=0 , ans=lmax;// capital
        while(cp<n){ // capital should maximum go to n-1th kingdom
            //cerr << cp << '\n';

            ans = min(ans , a*(v[cp] - 0) + b*(v[cp] - 0) + b*(pfSum(cp+1 , n , pf) - nelements(cp+1 ,v)*v[cp])) ;
            //cout << cp << ' ' << a*(v[cp] - 0) + b*(v[cp] - 0) + b*(pfSum(cp+1 , n , pf) - nelements(cp+1 ,v)*v[cp]) << '\n' ;
            //cout<< cp << ' ' << a*(v[cp] - 0) << ' ' << b*(v[cp] - 0) << ' ' << (pfSum(cp+1 , n , pf)) << ' '<< nelements(cp+1 ,v)*v[cp] << '\n' ;
            cp++;
        }
        cout << ans << '\n' ;
    }







    return 0;
}