#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    else return (b , b%a);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll k; cin >> k;
        vector<ll> v(k); set<ll> s;
        map<ll ,ll> mp;
        for(auto &i : v) {cin >> i;s.insert(i);mp[i]++;}
        // now n*m = k-2
        ll fg=0;
        for(auto i : v) {
            ll n = i , m;
            if((k-2)%n == 0){
                m = (k-2)/n;
                if(s.find(m)!=s.end()){
                    if((n==m && mp[m]>=2)  || n!=m){
                        cout << n << ' ' << m ;
                        fg=1; break;
                    }
                }
            }


            if(fg) break;
        }

        cout << '\n';
    }
    
    return 0;
}