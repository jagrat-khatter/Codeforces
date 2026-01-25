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
    cerr << "]\n";
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k; cin >> n >> k;
    string s; cin >> s;
    string news="", fn="";
    
    for(ll i=0;i<n;i++){ // O(n)
        news += s[i];

        string ans="";

        ll mul = k/(news.size());
        ll rem = k%(news.size());

        for(ll i=1;i<=mul;i++){ 
            ans += news;
        }
        for(ll i=0;i<rem;i++){// O(k) building
            ans += news[i] ;
        }
        if(fn.size()==0) fn=ans;
        else fn = min(fn , ans); // O(k) comparing

    }

    cout << fn << '\n' ; 


    return 0;
}