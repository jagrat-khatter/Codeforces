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
    cerr << "]\n";
}
ll pfSum(ll l,ll r,const vector<ll>& pf){
    return pf[r] - pf[l-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // In this optimized the space complezity while producing summation of products when a's segment
    // is in reverse, and also producing answer in less space
    ll n ; cin >> n;
    vector<ll> a(n+1) , b(n+1) , c(n+1);
    vector<ll> prev(n+1 ,0) , curr(n+1 ,0);
    for(ll i=1;i<=n;i++) {cin >> a[i];c[i]=a[i];}
    for(ll i=1;i<=n;i++) {cin >> b[i]; prev[i]=a[i]*b[i];}

    // we need to compute the prefix sum of multipication when a segment of a is in reverse order

    vector<ll> currEv(n+1 ,0),prevEv(n+1 ,0);
    vector<ll> currOd(n+1 ,0),prevOd(n+1 ,0);

    
    for(ll sz=1;sz<=1;sz++){
            for(ll i=1;i<=n-sz+1;i++){
                ll l=i , r=i+sz-1;
                if(sz==1) currOd[l] = (a[i]*b[i]); 
            }
            if(sz==1) swap(currOd , prevOd);
             
    }

   //cout << dp2[3][5] << '\n' ;

    
    
    

    
    for(ll sz=2;sz<=n;sz++){

        for(ll i=1;i<=n-sz+1;i++){
            ll l=i , r=i+sz-1;
            if(sz==2) currEv[l] = (a[l]*b[r]) + (a[r]*b[l]);
            else if(sz%2==0) currEv[l] = prevEv[l+1] + (a[l]*b[r]) + (a[r]*b[l]);
            else if(sz%2==1) currOd[l] = prevOd[l+1] + (a[l]*b[r]) + (a[r]*b[l]);

            ll reverseMS = (sz%2==0 ? currEv[l] : currOd[l]);

            curr[l] = max({reverseMS , prev[l] + (a[r]*b[r]), prev[l+1] + (a[l]*b[l])});
            
            //cout << l << ' ' << r << ' ' << dp[l][r] << '\n' ;
        }
        swap(prev , curr);

        if(sz%2==0) swap(currEv , prevEv);
        else swap(currOd , prevOd);
    }

    cout << prev[1] << '\n' ;



    return 0;
}