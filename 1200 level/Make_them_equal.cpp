#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll ops(ll a){ // complexity of 2^n(recursive aproach) use DP (N^2) approach
    ll ct=1 , ans=0;
    while(a>ct){
        ct = ct*2;
        ans++;
    }
    ll p;
    if(ct!=a) {ans--;p = ct/2;
        while(p!=a){
            ll  e = ((p +a -p -1 )/ (a-p));      // to ceil it
            p = p+(p/e);
            ans++;
        }
        return ans;
    }
    else return ans;

}
ll max(ll a , ll b){
    if(a>b) return a;
    else return b;
}
ll knapsack(vector<ll> &w , vector<ll> &pf , ll k , ll n){
    // we are assuming n in one  based indexing so in pf[n] -> pf[n-1] w[n]-> w[n-1]
    if(k==0 || n==0) return 0;

    if(w[n-1] > k){
        return knapsack(w , pf , k , n-1); // we have to skip n-1 the element
    }
    else {
        return max(pf[n-1] + knapsack(w,pf,k-w[n-1],n-1) , knapsack(w,pf,k,n-1));
    } // we can skip n-1 element or include it whichever makes it maximum
      // recursion will tell after accounting all the cases which is better deal  
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        vector<ll> b;
        for(ll i=0;i<n;i++){
            ll x; cin >> x; b.push_back(x);
        }
        vector<ll> w , pf; // first vector will have weight(number of ops) pf will have profit(number of coins)
        // we'll use knapsack approach
        ll ans=0;
        ll ct=n;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            if(ops(b[i])==0) {
                ans += x;
                ct--;
            } // if you are gaining coins without operations then take it it will disturb
            // the knapsack problem 
            else{
                w.push_back(ops(b[i]));
                pf.push_back(x);
            }
        }
        
        
        ans += knapsack(w , pf , k , ct);
        
        cout << ans << '\n';


    }



    return 0;
}