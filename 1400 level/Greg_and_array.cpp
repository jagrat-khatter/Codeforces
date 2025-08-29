#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    
    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
// ** In two different operations l and r can be same and d can be different 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,m,k; cin >> n >>m >> k;
        vector<ll> v;
        v.push_back(0);
        for(ll i=0;i<n;i++){
            ll x; cin >> x; v.push_back(x);
        }
        v.push_back(0);
        // making v such that we can perform range queries operations
        // now we want to memoize operations which will have three numbers each
        vector<pair<pair<ll,ll>,ll>> s; map<pair<ll,ll> , ll> mp;
        for(ll i=0;i<m;i++){ // now memoizig all the operations
            ll l,r,d; cin >> l >> r >> d;
            s.push_back({{l,r} , d});
        }
        // operations pair are stored in vector s in zero based indexing 
        vector<ll> op(m+2 , 0); // now counting how many times which operation shall be executed
        while(k--){
            ll x,y; cin >> x>> y;
            op[x]++;
            op[y+1]--;
        }
        
        // for(auto j : v) cout << j << ' ';

        // cout << '\n' ;
        
        for(ll i=1;i<op.size();i++){
            op[i] = op[i-1] + op[i];
        }
        // for(auto j : op) cout << j << ' ';

        // cout << '\n' ;
        vector<ll> vc(n+2 , 0);
        for(ll i=1;i<op.size()-1;i++){
            // first of all reteriving l and r of that operation
            ll l=s[i-1].first.first , r = s[i-1].first.second;
            ll d = s[i-1].second;
            //cout << l << ' ' <<r << ' ' << d  << ' ' << op[i]<< '\n' ;
            vc[l] += d*op[i];
            vc[r+1] -= d*op[i];
        }
        for(ll i=1;i<v.size();i++){
            vc[i] += vc[i-1];
        }
        for(ll i=1;i<v.size()-1;i++) cout << vc[i] + v[i] << ' ';

        cout << '\n' ;
    }



    return 0;
}