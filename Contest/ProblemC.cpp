#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1<= y < x <= k
    // qi = (x/y) (floored)
    // ri = (x%y)
    // if we selcet a unique pair of (x,y) then it will give unique pair {(x/y) , (x%y)}

    ll t; cin >> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        vector<ll> q(n) , r(n);
        for(auto &j : q) cin >> j;

        for(auto &j : r) cin >> j;

        
        vector<ll> sms; 

        for(ll i=0;i<n;i++){
            ll t = (r[i]+1);
            ll sm;

            if(k%t==r[i]) sm=(k/t);
            else sm=(k/t)-1;
            //cout << k << ' ' << t << ' '  << q[i] << ' ' <<  sm<< '\n';
            if(sm>0) sms.push_back(sm);// this means that any qi which is less than equal sm
        }

        sort(sms.begin() , sms.end());
        sort(q.begin() , q.end());

        // for(auto j : sms) cout << j << ' ';
        // cout << '\n' ;

        ll ans=0;
        ll ptr1=0 , ptr2=0; 
        while(ptr1<sms.size() && ptr2<q.size()){
            if(sms[ptr1]>=q[ptr2]) {ans++;ptr1++;ptr2++;}
            else ptr1++;
        }

        cout << ans << '\n' ;

    }



    return 0;
}