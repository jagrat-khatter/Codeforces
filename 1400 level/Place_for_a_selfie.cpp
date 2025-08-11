#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
 
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ld> v;
        for(ll i=0;i<n;i++){
            ld x; cin >> x; v.push_back(x);
        }
        sort(v.begin() , v.end());
        for(ll i=0;i<m;i++){
            ld a,b,c; cin >> a >> b >> c;
            if(4 * a * c <= (ld)0) {cout << "NO" << '\n'; continue;} // all lines passing from origin will have a soln
            ld p = sqrt(4*a*c);
            ld s1=-b-p , s2=-b+p;
            s1=-s1 ; s2=-s2;
            ld m1 = min(s1 , s2) , m2 = max(s1 , s2);
            // now the indices of element strictly greater than m1  and strictly less than m2;
            // 0 1 2 3 4 5 6
            ld l=0-1 , r=v.size()+1;
            while(r-1>l){
                ll mid = (l+r)/2;
                if(v[mid]<=m1) l=mid;
                else r=mid;
            }
            ll id1 = r;
            l=0-1 , r=v.size()+1;
            while(r-1>l){
                ll mid = (l+r)/2;
                if(v[mid]<m2) l=mid;
                else r=mid;
            }
            ll id2 = l;
            //cout << id1 << ' ' << id2 << '\n' ;
            if(id2-id1+1) {
                cout << "YES" << '\n';
                cout << (ll)v[id1];
                cout << '\n' ;
            }
            else cout << "NO" << '\n';
           
        }
         cout << '\n';
    }
 
 
 
    return 0;
}