#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
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
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        string sr; cin >> sr; ll n = sr.size();
        string f = sr+sr;
        vector<ll> r,p,s; r.push_back(0); p.push_back(0);s.push_back(0);
        for(auto i : f){
            if(i=='R') r.push_back(r[r.size()-1] + 1);
            else r.push_back(r[r.size()-1]);
            if(i=='P') p.push_back(p[p.size()-1] + 1);
            else p.push_back(p[p.size()-1]);
            if(i=='S') s.push_back(s[s.size()-1] + 1);
            else s.push_back(s[s.size()-1]);
        }


        string ans="";
        for(ll i=n;i<=2*n-1;i++){
            ll cr = r[i] - r[i-n];
            ll cp = p[i] - p[i-n];
            ll cs = s[i] - s[i-n];

            ll mx = max({cr , cp , cs});
            if(cr==mx) ans += 'P';
            else if(cp==mx) ans+= 'S';
            else ans+= 'R';
        }

        cout << ans << '\n';
    }



    return 0;
}