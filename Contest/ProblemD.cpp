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
bool comparator(ll a,ll b){
    return a>b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll l,w,r,g,b; cin >> l >> w >> r >> g >> b;
        
        ll ct = (r ? 1 : 0) + (g ? 1 : 0) + (b ? 1 : 0);
        ll ans=0;
        if(ct==1){
            ans=4;
        }
        else if(ct==2){
            ll c1 = max(r , g);
            ll c2 = max(g , b);
            if(c1==(2*l+w) || c2==(2*l+w) || c1==(2*w+l) || c2==(2*w+l)) ans=4;
            else if(c1==2*l || c1==2*w || c1==(l+w)) ans=4;
        }
        else if(ct==3){
            //cout << r << ' ' << g <<  ' ' << b << '\n' ;
            vector<ll> v={l,l,w,w};
            if(r==(l+l) && (g==w && b==w)) ans=4;
            else if(r==(w+w) && (g==l && b==l)) ans=4;
            else if(r==(w+l) && ((g==l && b==w) || (g==w && b==l))) ans=4;
            else if(g==(l+l) && (r==w && b==w)) ans=4;
            else if(g==(w+w) && (r==l && b==l)) ans=4;
            else if(g==(w+l) && ((r==l && b==w) || (r==w && b==l))) ans=4;
            else if(b==(l+l) && (g==w && r==w)) ans=4;
            else if(b==(w+w) && (g==l && r==l)) ans=4;
            else if(b==(w+l) && ((g==l && r==w) || (g==w && r==l))) ans=4;
        }

        if(ans!=4){
            if(ct==3){
                if(r==(l) || r==(w) || r==(l+l) || r==(w+w) || r==(w+l) || r==(w+w+l) || r==(l+l+w)) ans=5;
                else if(g==(l) || g==(w) || g==(l+l) || g==(w+w) || g==(w+l) || g==(w+w+l) || g==(l+l+w)) ans=5;
                else if(b==(l) || b==(w) || b==(l+l) || b==(w+w) || b==(w+l) || b==(w+w+l) || b==(l+l+w)) ans=5;
            }
            if(ct==2){
                ans=5;
            }
        }
        if(ans==0) ans=6;

        cout << ans << '\n' ;
    }



    return 0;
}