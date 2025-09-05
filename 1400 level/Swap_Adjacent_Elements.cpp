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
    if(b==0) return 1;
    
    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        map<ll ,ll> mp;
        for(ll i=0;i<n;i++) {
            ll x; cin >> x; v.push_back(x) ;mp[x] = i;
        }

        string s; cin >> s;

        vector<ll> sw;
        for(ll i=0;i<n-1;i++){
            ll num = (ll)(s[i]) - 48;
            sw.push_back(num);
        }
        for(ll i=1;i<n-1;i++){
            sw[i] += sw[i-1];
        }
        bool ans = true;
        // for(auto i : sw) cout << i << ' ';
        // cout << '\n' ;
        for(ll i=0;i<n;i++){
            if(v[i]!=i+1){
                ll id = mp[i+1];
                if(i!=0 && (sw[id-1] - sw[i-1] == id-i)){
                    
                    v[id] = v[i];
                    v[i] = i+1;// now orginals are restored
                    mp[v[id]] = id;
                    mp[i+1] = i;
                }
                else if(i==0 && (sw[id-1] - 0 == id-i)){
                    
                    v[id] = v[i];
                    v[i] = i+1;// now orginals are restored
                    mp[v[id]] = id;
                    mp[i+1] = i;
                }
                else {ans = false; break;}
            }
        }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n' ;

        if(ans) cout << "YES\n";
        else cout << "NO\n" ;

        
    }


    return 0;
}