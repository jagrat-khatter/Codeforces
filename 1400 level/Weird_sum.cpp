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
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,m ; cin >> n >> m;
        map<ll , vector<ll>> mpx,mpy;
        // for each color we'll store the elements of that color x's coordinates and y's coordinates
        set<ll> color;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                ll x; cin >> x; color.insert(x);
                mpx[x].push_back(i);
                mpy[x].push_back(j);
            }
        }
        ll ans=0;
        for(auto i : color){
            sort(mpx[i].begin() , mpx[i].end());
            sort(mpy[i].begin() , mpy[i].end());

            // cout << i << '\n';
            // for(auto j : mpx[i]) cout <<j << ' ';
            // cout << '\n' ;
            // for(auto j : mpy[i]) cout <<j << ' ';
            // cout << '\n' ;

            vector<ll> pfx , pfy;
            for(ll j=0;j<mpx[i].size();j++){
                if(j==0){
                    pfx.push_back(mpx[i][0]);
                    pfy.push_back(mpy[i][0]);
                }
                else{
                    pfx.push_back(pfx[j-1] + mpx[i][j]);
                    pfy.push_back(pfy[j-1] + mpy[i][j]);
                }
            }
            // for(auto j : pfx) cout <<j << ' ';
            // cout << '\n' ;
            // for(auto j : pfy) cout <<j << ' ';
            // cout << '\n' ;
            for(ll j=1;j<pfx.size();j++){
                ans += mpx[i][j] * j - pfx[j-1] ;
                ans += mpy[i][j] * j - pfy[j-1] ;
            }
        }
        cout << ans << '\n' ;

    }


    return 0;
}