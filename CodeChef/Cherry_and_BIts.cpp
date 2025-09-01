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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m ; cin >> n >> m;
    vector<vector<ll>> v(n+1 , vector<ll>(m+1)); // n rows and m columns matrix
    for(ll i=0;i<=n;i++){
        string s ;
        if(i) cin >> s;
        for(ll j=0;j<=m;j++){
            
            if(i==0 || j==0) v[i][j] = 0;
            else {ll num = (ll)s[j-1] - 48; v[i][j]=num;}
            //cout << v[i][j] << ' ';
        }
        //cout << '\n' ;
    }
    //now we can access in one based indexing 
    vector<vector<ll>> pf(n+1+1 , vector<ll>(m+1+1 , 0));//this is matrix which has operations
    vector<vector<ll>> pf2(n+1+1 , vector<ll>(m+1+1 , 0));// this is matrix that has 2D prefix sums
    ll q; cin >> q;
    while(q--){
        ll x1,y1,x2,y2; cin >> x1>>y1>>x2>>y2;
        pf[x1][y1]++; pf[x2+1][y2+1]++;
        pf[x1][y2+1]--;
        pf[x2+1][y1]--;
    }
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            pf2[i][j] = pf[i][j] + pf2[i-1][j] + pf2[i][j-1] - pf2[i-1][j-1];
        }
    }
    // for(auto i : pf2){
    //     for(auto j : i) cout << j << ' ';

    //     cout << '\n' ;
    // }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(pf2[i][j]%2!=0){// bits will flip
                if(v[i][j]) cout << '0' ;
                else cout << '1';
            }
            else {// dont bits will flip
                if(v[i][j]) cout << '1' ;
                else cout << '0';
            }
        }

        cout << '\n' ;
    }


    return 0;
}