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
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << " ";
    cerr << "]\n";

    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n ; cin >> n;
    string s; cin >> s;
    ll cp=0,cn=0;
    for(auto j : s){
        if(j=='+') cp++;
        else cn++;
    }
    ll qr; cin >> qr;
    while(qr--){
        ll p,q; 
        cin >> p >> q;
        // eqns
        // np1 = number of positive used with p , np2 = number of positive used with q
        // nm1 = number of minus used with p , nm2 = number of minus used withh q
        // np1 + np2 = cp 
        // nm1 + nm2 = cn
        // p * (np1 - nm1) + q * (np2 - nm2) = 0
        // on solving these three eqns we'll get k*(np1-nm1) = c;
        // in this c should be multiple of k
        ll k = (p-q) , c = q*(cn - cp);
        //cout << k << ' ' << c << '\n' ;
        if(k!=0 && c%k==0) {
            if(c/k>0 && cp>=c/k) cout << "YES" << '\n';
            else if(c/k<0 && cn>=abs(c/k)) cout << "YES\n";
            else if(c==0) cout << "YES\n";
            else cout << "NO\n" ;
        }
        else if(c==0 && k==0) cout << "YES\n" ;
        else cout << "NO" << '\n' ;
    }



    return 0;
}