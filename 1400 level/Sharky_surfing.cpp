#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        map<ll , ll> hr; // for storing hurdle pair
        vector<ll> v; // will store the initial points of hurdle
        for(ll i=0;i<n;i++){
            ll a,b; cin >> a >> b;
            hr[a]=b;
            v.push_back(a);
        }
        map<ll , vector<ll>> pwi; // powers in the interval
        for(ll i=0;i<m;i++){
            ll a,b; cin >> a >> b;
            ll l=0-1 , r=v.size()-1+1; // using zero based indexing
            while(r-1 > l){
                ll mid = (l+r)/2;
                if(v[mid] < a) l=mid;
                else r=mid;
            }
            if(r!=v.size()) pwi[v[r]].push_back(b);
        }
        // for each hurdle we'll see
        bool fg=true; ll ans=0;
        set<ll> s;map<ll , ll> ct;
        ll pwr = 1;
        for(auto i : v){
            ll l=i , r=hr[i];
            ll exp = r - l + 2;
            for(auto j : pwi[l]) {s.insert(j);ct[j]++;}

            while(s.size() && pwr<exp){
                ll me = *(--s.end());
                pwr += me; ans++;
                ct[me]--;
                if(ct[me]==0){
                    s.erase(me);
                }
            }
            if(pwr < exp) {fg=false; break;}
        }
        if(!fg) cout << -1 << '\n';
        else cout << ans << '\n' ;
    }



    return 0;
}