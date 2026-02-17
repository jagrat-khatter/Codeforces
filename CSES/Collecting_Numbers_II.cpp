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
    for(auto j : v) cerr << j <<  ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,qr; cin >> n>>qr ;
    ll ans=1;
    vector<ll> v(n+1);
    vector<ll> org(n+1);
    map<ll,ll> mp;

    for(ll i=1;i<=n;i++){
       cin >> org[i];
        mp[org[i]] = i;
    }
    for(ll i=1;i<=n;i++){// in this vector the value maps to index
        v[i] = mp[i] ;
        if(i!=1 && v[i]<v[i-1]) ans++;
    }
    //cout << ans << '\n' ;
    
    while(qr--){
        ll a,b; cin >> a >> b;
        if(a != b){// no change
        ll p = min(org[a],org[b]), q=max(org[a],org[b]);
        // if(a==18 && b==3) {
        //     for(ll i=1;i<=n;i++) cout << v[i] << ' ';
        //     cout << '\n' ;
            
        //     cout << org[a] << ' ' << org[b] << '\n';
        // }
        
        org[a] = org[a] + org[b];
        org[b] = org[a] - org[b];
        org[a] = org[a] - org[b];
        
        // effect due to p and q before swap
        ll e1=0;
        if(p!=1 && v[p-1]>v[p]) e1++;
        if(p!=n && v[p+1]<v[p]) e1++;
        if(q!=n && v[q+1]<v[q]) e1++;
        if(q!=1 && v[q-1]>v[q]) e1++;
        if(abs(p-q)==1 && v[p]>v[q]) e1--;
        

        v[p] = v[p] + v[q];
        v[q] = v[p] - v[q];
        v[p] = v[p] - v[q];
        
        // effect due to p and q after swap
        ll e2=0;
        if(p!=1 && v[p-1]>v[p]) e2++;
        if(p!=n && v[p+1]<v[p]) e2++;
        if(q!=n && v[q+1]<v[q]) e2++;
        if(q!=1 && v[q-1]>v[q]) e2++;
        if(abs(p-q)==1 && v[p]>v[q]) e2--;

        
        ans = ans - e1 + e2;

        // for(auto j : v) cout << j << ' ';
        // cout << '\n' ;
        }

        cout << ans << '\n' ;
    }




    return 0;
}