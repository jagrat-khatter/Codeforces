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
        vector<ll> v(n+1);
        set<ll> s;
        for(ll i=1;i<=n;i++){
            cin >> v[i]; s.insert(i);
        }
        bool ans = true;
        set<ll> rem;
        for(auto j: s){
            if(rem.find(j)!=rem.end()) continue;
            set<ll> ids;
            ll id = j;
            set<ll> vals;
            while(id<=n){
                ids.insert(id);
                vals.insert(v[id]);
                id *= 2;
            }
            for(auto k : vals){
                //cout << j << ' ' << k << '\n' ;
                ll ct = k;
                while(ct%2==0){
                    ct /= 2;
                }

                if(ct!=j) {ans=false; //cout << j << ' ' << k << '\n' ;
                    break;}
            }
            //cout << j << '\n';
            // for(auto k : ids)  cout << k << ' ';
            // cout << '\n' ;
            // for(auto k : s)  cout << k << ' ';
            // cout << '\n' ;
            
            if(ans==false) break;
            for(auto k : ids) rem.insert(k);
            // for(auto k : s)  cout << k << ' ';
            // cout << '\n' ;
            if(ans==false) break;
        }

        if(ans==true) cout << "YES\n";
        else cout << "NO\n" ;
    }




    return 0;
}