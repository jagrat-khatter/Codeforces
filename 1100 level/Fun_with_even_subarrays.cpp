#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll b,ll e){
    if(e==0)  return 1;
    ll value = power(b,e/2) ;
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll min(ll a,ll b) {
    if(a>b) return b;
    else return a;
} 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    
    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x; v.push_back(x);
        }
        // now the element that can be made in whole array is last element
        ll ans1=0 , e=v[n-1] , fg=0 ,ct1=0,ct2=0;
        for(ll i=n-1;i>=0;i--)
        {
            if(v[i]==e)  ct1++;
           else{ // now in the coming coming ct1 elements all the elements must be converted to e
                ans1++;
                i = i - (ct1-1) ;
                ct1 += ct1;
           }
        }
        
        
        cout <<ans1 << '\n';
    }


    return 0;
}