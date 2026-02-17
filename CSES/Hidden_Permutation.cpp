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
    return value*value*((e%2==0));
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

    ll n; cin >> n;
    vector<ll> ist(n);
    iota(ist.begin() , ist.end() , 1);

    stable_sort(ist.begin() , ist.end() , [](ll i,ll j){
        cout << "? " << i << ' ' << j << endl;
        string res; cin >> res;
        return (res == "YES");
    });


        
    
    cout << "! " ; 
    ll i=1;
    vector<ll> ans(n+1);
    for(auto j : ist){
        ans[j] = i;
        i++;
    }

    for(ll i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << '\n' ;
    



    return 0;
}