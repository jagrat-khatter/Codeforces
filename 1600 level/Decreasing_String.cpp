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
    for(auto j : v) cerr << j << " ";
    cerr << "]\n";  return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll sz = s.size();
        ll pos; cin >> pos;
        ll sum=0 , ct=0;
        while(pos>sum){
            ct++;
            sum += sz;
            sz--;
        }

        // now we find the i in Si 
        // number of elements to be remain
        sz = s.size();
        ll rem = sz - (ct - 1);
        vector<char> v;
        ll id=0;
        while(id < sz){
            if(v.size()==0) v.push_back(s[id]);
            else {
                // sz in one based indexing, rem in one based indexing and id in 0 based indexing

                while(v.size() && (v.back() > s[id]) && (v.size()-1 + (sz - id)>=rem)){
                    v.pop_back();
                }
                v.push_back(s[id]);
            }
            id++;
        }

        cout << v[(s.size()-ct+1) - (sum-pos) - 1];
        

        
    }





    return 0;
}