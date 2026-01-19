#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
vector<ll> pf;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
    return ;
}
ll pfSum(ll l,ll r,const vector<ll>& pf){
    return pf[r] - pf[l-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        vector<ll> v(n+1),ts(n+1);
        pf.resize(n+1 , 0);
        for(ll i=1;i<=n;i++){
            cin >> v[i];
        }
        
        for(ll i=1;i<=n;i++){
            cin >> ts[i];
            pf[i] = pf[i-1] + ts[i];
            //cout << pf[i] << ' ';
        }
        //cout << '\n' ;
        
        vector<ll> ans1(n+1), ans2(n+1); // in ans1 multiple of ts[i] in ans2 when <=
        for(ll i=1;i<=n;i++){
            ll l=i-1 , r=n+1 , e=v[i];
            while(r-1>l){
                ll mid = (l+r)/2;
                if(e >= pfSum(i , mid , pf)) l=mid;
                else r=mid;
            }
            //cout << l << ' ' << r << ' '<< e << '\n' ;
            if(l!=i-1) {ans1[i]++;if(r!=n+1) ans1[r]--;}
            if(r!=n+1 && pfSum(i , l , pf)!=e) ans2[r]+= (e-pfSum(i , l , pf));
        }
        // we need to take prefix sum of this ans to calculate frequency of ts elements used
        // ans is vector which stores when tea is tasted not in multiples of tasters capacity but in small
        for(ll i=1;i<=n;i++){
            ans1[i] += ans1[i-1];
            cout << ts[i]*ans1[i] + ans2[i] << ' ';
        }

        cout << '\n' ;
    }




    return 0;
}