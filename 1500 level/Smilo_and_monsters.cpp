#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++){
            cin >> v[i] ;
        }

        sort(v.begin() , v.end());
        ll p1=1 , p2=n , ct=0 , ans=0;
        while(p1<=p2){
             
            if(p1==p2){
                ans += ((v[p1]-ct+1) /2 );
                if((v[p1]-ct>=2) || (ct)) ans++;
                break;
            }
            if(v[p1]+ct<=v[p2]){
                ct+= v[p1];  ans+=v[p1];v[p1]=0;
            }
            else {
                v[p1] -= (v[p2]-ct);
                ans += (v[p2]-ct);
                ct += v[p2]-ct;
            }
            // while(v[p1] && (v[p2]>ct)){
            //     v[p1]--; ct++;ans++;
            // }
            if(v[p1]==0) p1++;
            if(v[p2]==ct) {v[p2]=0; ct=0; p2--; ans++;} 
            //cerr << p1 << ' ' << p2 << ' ' << ans << ' ' << '\n' ;
        }

        cout << ans << '\n' ;

    }




    return 0;
}