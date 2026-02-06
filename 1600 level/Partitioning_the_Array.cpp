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
vector<ll> divisorsOf(ll n){
    vector<ll> ans;
    for(ll i=1;i<=n;i++){
        if(n%i==0) ans.push_back(i);
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];

        vector<ll> divs = divisorsOf(n);

        ll ans=0;
        for(auto j : divs){
            
            vector<ll> igcds;
            for(ll k=1;k<=j;k++){
                ll id = k;
                vector<ll> temp;
                while(id<=n){
                    temp.push_back(v[id]);
                    id += j;
                }

                
                ll gccd = 0;
                for(ll i=1;i<temp.size();i++){
                    gccd = gcd(gccd , abs(temp[i] - temp[i-1]));
                }

                // if(j==3){
                //     cout << k << '\n';
                //     for(auto m : temp) cout << m << ' ';
                //     cout << '\n' ;
                // } 
                igcds.push_back(gccd); 
            }
            ll ansgcd=0;
            for(ll i=0;i<igcds.size();i++){
                ansgcd = gcd(ansgcd , igcds[i]);
            }
            //cout << j << ' ' << ansgcd << '\n' ; 
            if(ansgcd>=2 || ansgcd==0) ans++;
        
        }
        
        cout << ans << '\n' ;
    }





    return 0;
}