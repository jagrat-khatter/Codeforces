#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b ,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> v(m);
        set<ll> s;
        for(auto &i : v) {cin >> i; s.insert(i);}
        ll l=0-1 , r=2*m + 1;
        map<ll,ll> mp;
        for(auto i : v){
            mp[i]++;
        }
        while(r-1>l){
            
            ll t = (l+r)/ 2;
            ll power=0;
            ll ct=0;ll rem=m;
            for(auto i : s){
                if(i<=n) {if(t>mp[i]) {power+=(t-mp[i])/2; rem-= (mp[i]);}
                else rem -= (t);
                ct++;}
            }
            // workers not used up untill now n-ct
            power += ((n-ct) * ((t)/2));

            // now there might be some tasks remaining that did not find desired workers
            
            //cout << t << ' ' << power << ' ' << rem << '\n' ;
            if(power>=rem) r=t;
            else l=t;
        }

        cout << r << '\n' ;
    }




    return 0;
}