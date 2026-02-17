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

    vector<ll> pw2(1e5+1 , 0);
    ll ct=1;
    for(ll i=0;i<=1e5;i++){
        if(ct<1e12) {pw2[i]=ct; ct *= 2;}
        else pw2[i]=pw2[i-1]; // this does not matter becuase a[i]/pw2[i] will be 0 only 
        
    }

    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n>> k;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++) cin >> v[i];

        vector<ll> curr(34 ,0) , prev(34 ,0);
        // we only need j upto 32 in dp[i][j]
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<=33;j++){
                curr[j]=0; // cleaning the curr vector becuase it will become next prev vector 
            }
            
            if(i==1){
                curr[0]=v[i]-k;
                curr[1]=((v[i]/pw2[1])) ;
            }
            else {
                for(ll j=0;j<=min((ll)33 , i);j++){
                    
                    curr[j] = prev[j]-k+(v[i]/pw2[j]);
                    if(j>0) curr[j] = max(prev[j-1]+(v[i]/pw2[j]) , curr[j]);
                    if(j==33) curr[j] = max(curr[j] , prev[j]); // becuase when j is 33 we are considering that 
                    // j>=33 in these cases curr[j] and prev[j] will remain same because there will be no increment
                }
            }
            // cout << curr[0] <<  ' ' <<curr[1] << ' '<< curr[2] << ' ' << curr[3] << ' ' << curr[4] << '\n' ;
            swap(curr , prev);
        }

        ll ans= lmin;
        for(ll j=0;j<=33;j++){
            ans = max(ans , prev[j]);
        }

        cout << ans << '\n' ;
    }




    return 0;
}