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
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> v(26+1 ,0);
        for(auto j : s){
            
            ll ct ;
            if((ll)(j)<97) ct = (ll)(j) - 65 + 1;
            else ct = (ll)(j) - 97 + 1;
            v[ct]++;
        }

        multiset<ll> st;
        for(auto j : v) {
            //cout << j << ' ';
            if(j>0) st.insert(j);
        }
        //cout << *(--st.end())<< ' ' << *(--(--st.end())) << '\n' ;
        if(st.size()==1) cout << *(--st.end());
        else cout  << ((*(--st.end())) + (*(--(--st.end()))) );
        cout << '\n' ;
    }




    return 0;
}