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
    else return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--){
        ll n,l,r; cin >> n >> l >> r;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;
        sort(v.begin() , v.end());
        ll ls =0 , mr =0; // elements whose sum is less than l and elements whose sum is more than r 

        ll pt1 = -1 ;
        while(v[pt1+1] + v[0] < l && pt1<n){
            pt1++;
        }
        if(pt1 == n) pt1--;
        for(ll i=0;i<n && pt1>i;i++){
            while(v[pt1] + v[i] >= l && pt1>i) pt1--;

            ls += pt1 - i;
        }
        ll pt2 = 0;
        while(v[pt2] + v[0] <=r  && pt2<n) pt2++;

        //cout << pt2 <<'\n' ;
        for(ll i=0;i<n;i++){ 
            while(v[pt2-1] + v[i] > r && pt2>=0) pt2--;
            //cout << pt2 << '\n' ;
            
            //cout << i << ' ' << n - max(pt2 , i+1) << '\n' ;
            mr += n - max(pt2 , i+1);
            //cout << mr << '\n' ;
        }

        cout << (n * (n-1) / 2) -  ls - mr<< '\n' ;
    }




    return 0;
}