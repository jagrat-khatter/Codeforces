#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll q; cin >> q;
        while(q--){
            char a,b; cin >> a >> b;

            if(a=='-'){
                ll x,y; cin >> x >> y;
                ll sz = power(2 , n);
                ll ct = sz/2;
                vector<ll> v;
                while(ct!=0){
                    if(x>ct && y>ct) {x=x-ct; y=y-ct; v.push_back(2);} 
                    else if(x>ct && y<=ct) {x=x-ct;  v.push_back(3);}
                    else if(x<=ct && y>ct) {y=y-ct; v.push_back(4);}
                    else if(x<=ct && y<=ct) {v.push_back(1);}
                    ct = ct/2;
                }
                // for(auto i : v) cout << i << ' ' ;
                // cout << '\n';
                reverse(v.begin() , v.end());
                ct=1;
                ll ans=0;
                for(ll i=0;i<v.size();i++){
                    if(i==0) ans += v[i] * ct;
                    else ans += (v[i]-1) * ct;
                    ct *= 4;
                }
                cout << ans << '\n';
            }
            else{
                ll d; cin >> d;
                ll sz = power(2 , n);
                vector<ll> v;
                while(sz!=1){
                    ll a = sz*sz / 4;
                    ll p = (d+a-1)/a ;
                    v.push_back(p);
                    d = d - a*(p-1);
                    sz = sz/2;
                }
                reverse(v.begin() , v.end());
                ll x,y;
                if(v[0]==1) {x=1;y=1;}
                else if(v[0]==2) {x=2;y=2;}
                else if(v[0]==3) {x=2;y=1;}
                else if(v[0]==4) {x=1;y=2;}
                ll ct=2;
                for(ll i=1;i<v.size();i++){
                    if(v[i]==1) {x+=0; y+=0;}
                    else if(v[i]==2) {x+=ct; y+=ct;}
                    else if(v[i]==3) {x+=ct; y+=0;}
                    else if(v[i]==4) {x+=0; y+=ct;}
                    ct *=2;
                }
                cout <<x << ' ' << y << '\n' ;
            }
        }
    }
    

    return 0;
}