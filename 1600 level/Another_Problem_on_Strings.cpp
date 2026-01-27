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

    ll k; cin >> k;
    string s; cin >> s;
    ll n=s.size();

    vector<ll> pf(n+1 ,0);
    for(ll i=1;i<=n;i++){
        if(s[i-1]=='1') pf[i] = pf[i-1] + 1;
        else pf[i] = pf[i-1];
        //cout << pf[i] <<' ';
    }

    //cout << '\n' ;

    ll ptr=1 ,ans=0;
    while(ptr<=n){
        //cout << ptr << '\n' ;
        ll look;
        if(s[ptr-1]=='1') look=pf[ptr]+k-1;
        else look=pf[ptr]+k;

        if(pf[n]<look) break;

        ll tr1=0,tr2=0; // leading zeroes in beginning and trailing zeroes in the end
        if(s[ptr-1]=='1') tr1=0;
        else {
            ll l=ptr+1-1 , r=n+1;
            
            while(r-1>l){
                ll mid = (l+r)/2;
                if(pf[mid]<=pf[ptr]) l=mid;
                else r=mid;
            }
            
            tr1 = r-ptr;
        }

        // now we need to find what we are looking for
        ll l=ptr-1 , r=n+1;
        while(r-1>l){
            ll mid = (l+r)/2;
            if(pf[mid]<look) l=mid;
            else r=mid;
        }
        
        tr2=r;
        l=ptr-1 , r=n+1;
        while(r-1>l){
            ll mid = (l+r)/2;
            if(pf[mid]<=look) l=mid;
            else r=mid;
        }
        //if(look==1) cout << l << ' ' << r << '\n' ;
        tr2=l-tr2;
        //cout << ptr << ' ' << look << ' ' << tr1 << ' ' << tr2 <<'\n' ;
        if(k!=0) ans += ((tr1+1) * (tr2+1));
        else ans += (tr1)*(tr1+1)/2;

        while(1 && ptr<=n){
            if(s[ptr-1]=='1') {ptr++;break;}
            else ptr++;
        }

    }

    cout << ans << '\n' ;




    return 0;
}